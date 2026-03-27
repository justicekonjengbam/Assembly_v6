using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Unity.Sentis;
using System.Collections;
using TMPro; 

public class YOLOHoloLens : MonoBehaviour
{
    [System.Serializable]
    public struct DetectionMapping {
        public string labelInFile;       
        public GameObject modelObject;   
        public GameObject nameLabelText; 
    }

    [Header("Model Settings")]
    public ModelAsset yoloModel;
    public string outputName = "output0";

    [Header("UI References")]
    public RawImage displayImage; 
    public RectTransform boxContainer; 
    public GameObject boxPrefab; 
    public TextAsset classesFile; 
    public TMP_Text statusText; 
    
    [Header("Sequence UI")]
    public GameObject instructionCanvas; 
    public GameObject scanDisplayCanvas; 
    public TMP_Text countdownText;

    [Header("Detection Mapping")]
    public List<DetectionMapping> mappings;

    [Header("Settings")]
    [Tooltip("Increase this to 0.5 or 0.6 to stop phantom detections!")]
    [Range(0, 1)] public float scoreThreshold = 0.5f; 
    public int inputWidth = 640;
    public int inputHeight = 640;
    public bool flipY = true; 

    private Worker worker;
    private WebCamTexture webcamTexture;
    private RenderTexture renderTexture;
    private List<string> classNames = new List<string>();
    private List<GameObject> activeBoxes = new List<GameObject>();
    private bool isProcessing = false;

    private struct Detection {
        public int classIndex;
        public float score;
        public Rect rect; 
    }

    void Start() {
        if (yoloModel == null) return;

        worker = new Worker(ModelLoader.Load(yoloModel), BackendType.GPUCompute);

        if (classesFile != null) {
            string[] lines = classesFile.text.Split('\n');
            foreach (var line in lines) {
                if (!string.IsNullOrWhiteSpace(line)) classNames.Add(line.Trim().ToLower());
            }
        }

        if (WebCamTexture.devices.Length > 0) {
            webcamTexture = new WebCamTexture(640, 480);
            webcamTexture.Play();
            
            // FORCE CAMERA VISIBILITY
            if (displayImage != null) {
                displayImage.texture = webcamTexture;
                displayImage.color = Color.white; 
            }
        }

        renderTexture = new RenderTexture(inputWidth, inputHeight, 0, RenderTextureFormat.ARGB32);
        
        if (instructionCanvas != null) instructionCanvas.SetActive(false);
        if (scanDisplayCanvas != null) scanDisplayCanvas.SetActive(false);
        if (statusText != null) statusText.text = "System Ready";
    }

    public void Scan() {
        if (!isProcessing) StartCoroutine(RunInferenceRoutine());
    }

    public void ClearBoxes() {
        foreach (var b in activeBoxes) Destroy(b);
        activeBoxes.Clear();
        if (statusText != null) statusText.text = "Cleared";
    }

    private IEnumerator RunInferenceRoutine() {
        isProcessing = true;
        
        if (instructionCanvas != null) instructionCanvas.SetActive(true);
        if (scanDisplayCanvas != null) scanDisplayCanvas.SetActive(false);
        if (statusText != null) statusText.text = "Please look at the parts to be scanned";

        for (int i = 3; i > 0; i--) {
            if (countdownText != null) countdownText.text = i.ToString();
            yield return new WaitForSeconds(1f);
        }

        if (instructionCanvas != null) instructionCanvas.SetActive(false);
        if (scanDisplayCanvas != null) scanDisplayCanvas.SetActive(true);
        if (countdownText != null) countdownText.text = "Scanning...";

        yield return new WaitForEndOfFrame();

        Graphics.Blit(webcamTexture, renderTexture);
        using Tensor<float> inputTensor = TextureConverter.ToTensor(renderTexture, inputWidth, inputHeight, 3);
        worker.Schedule(inputTensor);

        yield return null; 

        var output = worker.PeekOutput(outputName) as Tensor<float>;
        using var outputCPU = output.ReadbackAndClone(); 
        
        List<Detection> detections = ParseDetections(outputCPU);
        
        UpdateUI(detections);
        ActivateMappedObjects(detections);

        if (statusText != null) {
            statusText.text = detections.Count > 0 ? $"Found {detections.Count} objects" : "No objects detected";
        }

        yield return new WaitForSeconds(5f);

        ClearBoxes();
        if (scanDisplayCanvas != null) scanDisplayCanvas.SetActive(false);

        isProcessing = false;
    }

    List<Detection> ParseDetections(Tensor<float> output) {
        List<Detection> detections = new List<Detection>();
        int numAttributes = output.shape[1]; 
        int numBoxes = output.shape[2];      

        for (int i = 0; i < numBoxes; i++) {
            float maxScore = 0;
            int classIdx = 0;
            for (int c = 4; c < numAttributes; c++) {
                if (output[0, c, i] > maxScore) {
                    maxScore = output[0, c, i];
                    classIdx = c - 4;
                }
            }

            if (maxScore > scoreThreshold) {
                detections.Add(new Detection {
                    classIndex = classIdx,
                    score = maxScore,
                    rect = new Rect(output[0, 0, i] / inputWidth, output[0, 1, i] / inputHeight, 
                                    output[0, 2, i] / inputWidth, output[0, 3, i] / inputHeight)
                });
            }
        }
        return detections;
    }

    void UpdateUI(List<Detection> detections) {
        ClearBoxes();
        float cx = boxContainer.rect.width;
        float cy = boxContainer.rect.height;

        foreach (var det in detections) {
            GameObject go = Instantiate(boxPrefab, boxContainer);
            activeBoxes.Add(go);

            RectTransform rt = go.GetComponent<RectTransform>();
            rt.anchorMin = Vector2.zero;
            rt.anchorMax = Vector2.zero;
            rt.pivot = new Vector2(0.5f, 0.5f);

            float w = det.rect.width * cx;
            float h = det.rect.height * cy;
            float x = det.rect.x * cx;
            float y = det.rect.y * cy;

            if (flipY) y = cy - y; 

            rt.anchoredPosition = new Vector2(x, y);
            rt.sizeDelta = new Vector2(w, h);

            TMP_Text t = go.GetComponentInChildren<TMP_Text>();
            if (t != null && det.classIndex < classNames.Count) {
                // Formats it exactly like: Tool (95%)
                t.text = $"{classNames[det.classIndex]} ({det.score * 100f:F0}%)";
            }
        }
    }

    void ActivateMappedObjects(List<Detection> detections) {
        foreach (var det in detections) {
            if (det.classIndex >= classNames.Count) continue;
            string detectedLabel = classNames[det.classIndex];

            foreach (var map in mappings) {
                if (map.labelInFile.Trim().ToLower() == detectedLabel) {
                    if (map.modelObject != null) ForceActivate(map.modelObject);
                    if (map.nameLabelText != null) ForceActivate(map.nameLabelText);
                }
            }
        }
    }

    // THE FIX: This forces the assigned object AND its disabled parents to turn on.
    void ForceActivate(GameObject obj) {
        Transform current = obj.transform;
        while (current != null) {
            current.gameObject.SetActive(true);
            current = current.parent;
        }
    }

    void OnDisable() {
        worker?.Dispose();
        if (webcamTexture != null) webcamTexture.Stop();
    }
}