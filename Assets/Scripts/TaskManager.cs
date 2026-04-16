using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Unity.Sentis;
using System.Collections;
using TMPro;
using Microsoft.MixedReality.OpenXR;
using System.Linq;
using MixedReality.Toolkit.UX;

public class TaskMaster : MonoBehaviour
{
    [System.Serializable]
    public struct TaskRequirement {
        public string taskName;
        [Header("Detection")]
        public List<string> requiredYoloLabels;
        public List<string> requiredQrTexts;
        
        [Header("Assembly")]
        public Transform[] assemblyTargets; 
        public GameObject[] partsToMove;

        [Header("Internal UI")]
        public PressableButton scanButton;
        public Renderer scanRenderer;
        public PressableButton verificationButton;
        public Renderer verificationRenderer;
        public PressableButton assemblyButton;
        public Renderer assemblyRenderer;
        
        [Header("Main Menu UI")]
        public PressableButton menuTaskButton;
        public Renderer menuButtonBackplate;
    }

    public List<TaskRequirement> tasks;
    public int currentTaskIndex = 0; 
    
    [Header("AI & Vision")]
    public ModelAsset yoloModel;
    public ARMarkerManager qrManager;
    public TextAsset classesFile;
    public RawImage displayImage; 
    public RectTransform boxContainer; 
    public GameObject boxPrefab;

    [Header("Inference Settings")]
    public bool flipY = true;
    [Range(0, 1)] public float scoreThreshold = 0.5f;

    private Worker worker;
    private WebCamTexture webcamTexture;
    private RenderTexture renderTexture;
    private List<string> classNames = new List<string>();
    private List<GameObject> activeBoxes = new List<GameObject>();
    private bool isScanning = false;
    private HashSet<string> seenYoloThisScan = new HashSet<string>();
    private HashSet<string> seenQrThisScan = new HashSet<string>();

    private Color LockedColor = Color.red;
    private Color ActiveColor = Color.yellow;
    private Color DoneColor = Color.green;

    void Start() {
        if (yoloModel != null) worker = new Worker(ModelLoader.Load(yoloModel), BackendType.GPUCompute);
        if (classesFile != null) {
            foreach (var line in classesFile.text.Split('\n')) 
                if (!string.IsNullOrWhiteSpace(line)) classNames.Add(line.Trim().ToLower());
        }
        if (WebCamTexture.devices.Length > 0) {
            webcamTexture = new WebCamTexture(640, 480);
            webcamTexture.Play();
            if (displayImage != null) displayImage.texture = webcamTexture;
        }
        // Force square 640x640 for Sentis, but we calibrate UI mapping below
        renderTexture = new RenderTexture(640, 640, 0, RenderTextureFormat.ARGB32);
        InitializeWorkflow();
    }

    void InitializeWorkflow() {
        for (int i = 0; i < tasks.Count; i++) {
            UpdateMenuButton(i, i == 0 ? ActiveColor : LockedColor);
            UpdateTaskButtons(i, false, false, false); 
        }
    }

    public void CompleteOverview() {
        UpdateMenuButton(0, DoneColor);
        currentTaskIndex = 1; 
        UpdateMenuButton(1, ActiveColor);
        UpdateTaskButtons(1, true, false, false); 
    }

    public void StartTaskScan() {
        if (isScanning || currentTaskIndex >= tasks.Count) return;
        seenYoloThisScan.Clear();
        seenQrThisScan.Clear();
        StartCoroutine(CombinedScanRoutine());
    }

    private IEnumerator CombinedScanRoutine() {
        isScanning = true;
        if (qrManager != null) qrManager.markersChanged += OnQrChanged;
        float timer = 0;
        while (timer < 5.0f) {
            timer += Time.deltaTime;
            // Crop/Stretch logic for YOLO
            Graphics.Blit(webcamTexture, renderTexture);
            using Tensor<float> input = TextureConverter.ToTensor(renderTexture, 640, 640, 3);
            worker.Schedule(input);
            yield return null;
            var output = worker.PeekOutput("output0") as Tensor<float>;
            using var outputCPU = output.ReadbackAndClone();
            UpdateVisionUI(ParseDetections(outputCPU));
            yield return new WaitForSeconds(0.05f);
        }
        if (qrManager != null) qrManager.markersChanged -= OnQrChanged;
        ClearBoxes();
        isScanning = false;
        CheckVerificationStatus();
    }

    void UpdateVisionUI(List<Detection> detections) {
        ClearBoxes(); if (boxContainer == null) return;
        float cx = boxContainer.rect.width;
        float cy = boxContainer.rect.height;

        foreach (var det in detections) {
            if (det.classIndex >= classNames.Count) continue;
            string label = classNames[det.classIndex]; 
            seenYoloThisScan.Add(label);

            GameObject go = Instantiate(boxPrefab, boxContainer); activeBoxes.Add(go);
            RectTransform rt = go.GetComponent<RectTransform>();
            rt.anchorMin = Vector2.zero; rt.anchorMax = Vector2.zero; rt.pivot = new Vector2(0.5f, 0.5f);

            // CALIBRATED MAPPING: Maps 0-1 Sentis space to UI Rect space
            float posX = det.rect.x * cx;
            float posY = flipY ? cy - (det.rect.y * cy) : det.rect.y * cy;

            rt.anchoredPosition = new Vector2(posX, posY);
            rt.sizeDelta = new Vector2(det.rect.width * cx, det.rect.height * cy);

            TMP_Text t = go.GetComponentInChildren<TMP_Text>(); if (t != null) t.text = label;
        }
    }

    void CheckVerificationStatus() {
        var req = tasks[currentTaskIndex];
        bool yoloPass = req.requiredYoloLabels.All(l => seenYoloThisScan.Contains(l.ToLower()));
        bool qrPass = req.requiredQrTexts.All(q => seenQrThisScan.Contains(q.ToLower()));

        if (yoloPass && qrPass) {
            SetManualButtonColor(req.scanRenderer, DoneColor);
            SetManualButtonColor(req.verificationRenderer, ActiveColor);
            SetButtonInteraction(req.verificationButton, true);
        }
    }

    // --- UPDATED: PARTS FLY ON VERIFICATION NOW ---
    public void PressVerification() {
        var req = tasks[currentTaskIndex];
        SetManualButtonColor(req.verificationRenderer, DoneColor);
        SetManualButtonColor(req.assemblyRenderer, ActiveColor);
        SetButtonInteraction(req.assemblyButton, true);

        // TRIGGER ASSEMBLY FLIGHT HERE
        StartCoroutine(AssemblePartsRoutine(req));
    }

    public void PressAssembly() {
        var req = tasks[currentTaskIndex];
        SetManualButtonColor(req.assemblyRenderer, DoneColor);
        UpdateMenuButton(currentTaskIndex, DoneColor);
        
        currentTaskIndex++;
        if (currentTaskIndex < tasks.Count) {
            UpdateMenuButton(currentTaskIndex, ActiveColor);
            UpdateTaskButtons(currentTaskIndex, true, false, false);
        }
    }

    private IEnumerator AssemblePartsRoutine(TaskRequirement req) {
        float elapsed = 0;
        float duration = 1.5f;
        Vector3[] startPos = new Vector3[req.partsToMove.Length];
        Quaternion[] startRot = new Quaternion[req.partsToMove.Length];

        for (int i = 0; i < req.partsToMove.Length; i++) {
            if (req.partsToMove[i] != null) {
                startPos[i] = req.partsToMove[i].transform.position;
                startRot[i] = req.partsToMove[i].transform.rotation;
                // Make kinematic so they don't fall or collide during flight
                var rb = req.partsToMove[i].GetComponent<Rigidbody>();
                if (rb != null) rb.isKinematic = true;
            }
        }

        while (elapsed < duration) {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0, 1, elapsed / duration);
            for (int i = 0; i < req.partsToMove.Length; i++) {
                if (req.partsToMove[i] != null && i < req.assemblyTargets.Length) {
                    req.partsToMove[i].transform.position = Vector3.Lerp(startPos[i], req.assemblyTargets[i].position, t);
                    req.partsToMove[i].transform.rotation = Quaternion.Lerp(startRot[i], req.assemblyTargets[i].rotation, t);
                }
            }
            yield return null;
        }
    }

    // --- UI & COLOR HELPERS ---
    void SetManualButtonColor(Renderer rend, Color c) {
        if (rend != null) rend.material.SetColor("_Base_Color_", c);
    }

    void UpdateMenuButton(int idx, Color c) {
        SetManualButtonColor(tasks[idx].menuButtonBackplate, c);
        SetButtonInteraction(tasks[idx].menuTaskButton, c != LockedColor);
    }

    void UpdateTaskButtons(int idx, bool scan, bool ver, bool ass) {
        SetButtonInteraction(tasks[idx].scanButton, scan);
        SetManualButtonColor(tasks[idx].scanRenderer, scan ? ActiveColor : LockedColor);
        SetButtonInteraction(tasks[idx].verificationButton, ver);
        SetManualButtonColor(tasks[idx].verificationRenderer, ver ? ActiveColor : LockedColor);
        SetButtonInteraction(tasks[idx].assemblyButton, ass);
        SetManualButtonColor(tasks[idx].assemblyRenderer, ass ? ActiveColor : LockedColor);
    }

    void SetButtonInteraction(PressableButton b, bool state) {
        if (b != null) {
            var col = b.GetComponentInChildren<Collider>();
            if (col != null) col.enabled = state;
        }
    }

    void OnQrChanged(ARMarkersChangedEventArgs args) {
        foreach (var marker in args.added) seenQrThisScan.Add(marker.GetDecodedString().Trim().ToLower());
        foreach (var marker in args.updated) seenQrThisScan.Add(marker.GetDecodedString().Trim().ToLower());
    }

    public void ClearBoxes() { foreach (var b in activeBoxes) Destroy(b); activeBoxes.Clear(); }
    private struct Detection { public int classIndex; public Rect rect; }

    List<Detection> ParseDetections(Tensor<float> output) {
        List<Detection> detections = new List<Detection>();
        // Check output shape for YOLO v8 [batch, attributes, boxes]
        for (int i = 0; i < output.shape[2]; i++) {
            float maxScore = 0; int classIdx = 0;
            for (int c = 4; c < output.shape[1]; c++) {
                if (output[0, c, i] > maxScore) { maxScore = output[0, c, i]; classIdx = c - 4; }
            }
            if (maxScore > scoreThreshold) {
                // Sentis 0-1 coordinates
                detections.Add(new Detection { 
                    classIndex = classIdx, 
                    rect = new Rect(output[0, 0, i]/640, output[0, 1, i]/640, output[0, 2, i]/640, output[0, 3, i]/640)
                });
            }
        }
        return detections;
    }

    void OnDisable() { worker?.Dispose(); if (webcamTexture != null) webcamTexture.Stop(); }
}