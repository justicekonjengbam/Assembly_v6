using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Unity.Sentis;
using System.Collections;
using TMPro;
using MixedReality.Toolkit.UX; 

public class DETECTOR : MonoBehaviour
{
    [System.Serializable]
    public struct DetectionMapping {
        public string labelInFile;       
        public GameObject modelObject;   
    }

    [Header("Model Settings")]
    public ModelAsset yoloModel;
    public string outputName = "output0";

    [Header("References")]
    public GroupAssembler assembler; // Reference added here
    public RawImage displayImage; 
    public RectTransform boxContainer; 
    public GameObject boxPrefab; 
    public TextAsset classesFile; 
    public TMP_Text statusText; 
    
    [Header("Sequence UI")]
    public GameObject retryMenu; 

    [Header("Detection Mapping")]
    public List<DetectionMapping> mappings;

    [Header("Settings")]
    [Range(0, 1)] public float scoreThreshold = 0.5f; 
    public int inputWidth = 640;
    public int inputHeight = 640;
    public bool flipY = true; 
    public float scanDuration = 5.0f; 

    [Header("3D Placement Settings")]
    public LayerMask spatialMeshLayer = ~0; 
    public float maxRaycastDistance = 3.0f;
    [Tooltip("Height in meters above the detected surface (0.1 = 10cm)")]
    public float spawnHeightOffset = 0.1f;

    private Worker worker;
    private WebCamTexture webcamTexture;
    private RenderTexture renderTexture;
    private List<string> classNames = new List<string>();
    private List<GameObject> activeBoxes = new List<GameObject>();
    private Coroutine scanSequenceCoroutine;

    // --- RESET LOGIC STORAGE ---
    private HashSet<GameObject> detectedInThisSession = new HashSet<GameObject>();
    private Dictionary<GameObject, Pose> originalPoses = new Dictionary<GameObject, Pose>();
    private Dictionary<GameObject, Vector3> originalScales = new Dictionary<GameObject, Vector3>();

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
            if (displayImage != null) {
                displayImage.texture = webcamTexture;
                displayImage.color = Color.white; 
            }
        }

        renderTexture = new RenderTexture(inputWidth, inputHeight, 0, RenderTextureFormat.ARGB32);
        if (retryMenu != null) retryMenu.SetActive(false);
    }

    public void ResetScaleAndPosition() {
        foreach (var obj in detectedInThisSession) {
            if (obj != null && originalPoses.ContainsKey(obj)) {
                obj.transform.position = originalPoses[obj].position;
                obj.transform.rotation = originalPoses[obj].rotation;
                obj.transform.localScale = originalScales[obj];
                
                Rigidbody rb = obj.GetComponent<Rigidbody>();
                if (rb != null) {
                    rb.velocity = Vector3.zero;
                    rb.angularVelocity = Vector3.zero;
                }
            }
        }
    }

    public void RemoveAllObjects() {
        foreach (var obj in detectedInThisSession) {
            if (obj != null) obj.SetActive(false);
        }
        detectedInThisSession.Clear();
        originalPoses.Clear();
        originalScales.Clear();
    }

    public void OnSliderUpdated(SliderEventData eventData) {
        scoreThreshold = eventData.NewValue;
    }

    public void StartScanSequence() {
        if (retryMenu != null) retryMenu.SetActive(false);
        if (scanSequenceCoroutine != null) StopCoroutine(scanSequenceCoroutine);
        scanSequenceCoroutine = StartCoroutine(TimedScanRoutine());
    }

    private IEnumerator TimedScanRoutine() {
        float timer = 0;
        while (timer < scanDuration) {
            timer += Time.deltaTime;
            if (statusText != null) 
                statusText.text = $"Scanning... {Mathf.Ceil(scanDuration - timer)}s";

            Graphics.Blit(webcamTexture, renderTexture);
            using Tensor<float> inputTensor = TextureConverter.ToTensor(renderTexture, inputWidth, inputHeight, 3);
            worker.Schedule(inputTensor);

            yield return null; 

            var output = worker.PeekOutput(outputName) as Tensor<float>;
            using var outputCPU = output.ReadbackAndClone(); 
            
            List<Detection> detections = ParseDetections(outputCPU);
            UpdateUI(detections); 
            ActivateMappedObjects(detections);

            yield return new WaitForSeconds(0.05f);
        }

        if (statusText != null) statusText.text = "";
        ClearBoxes();

        foreach (var obj in detectedInThisSession) {
            ReleaseToWorld(obj);
        }

        // NEW: Sync the Assembler so it knows where we placed the parts
        if (assembler != null) {
            assembler.CaptureHomeState();
        }
        
        if (retryMenu != null) retryMenu.SetActive(true);
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
                t.text = $"{classNames[det.classIndex]}";
            }
        }
    }

    void ActivateMappedObjects(List<Detection> detections) {
        foreach (var det in detections) {
            if (det.classIndex >= classNames.Count) continue;
            string detectedLabel = classNames[det.classIndex];

            foreach (var map in mappings) {
                if (map.labelInFile.Trim().ToLower() == detectedLabel) {
                    if (map.modelObject != null) PlaceObjectIn3D(map.modelObject, det);
                }
            }
        }
    }

    void PlaceObjectIn3D(GameObject obj, Detection det) {
        float centerX = det.rect.x + (det.rect.width / 2f);
        float centerY = det.rect.y + (det.rect.height / 2f);
        if (flipY) centerY = 1.0f - centerY;

        Ray ray = Camera.main.ViewportPointToRay(new Vector3(centerX, centerY, 0));
        Vector3 spawnPos;

        if (Physics.Raycast(ray, out RaycastHit hit, maxRaycastDistance, spatialMeshLayer)) {
            spawnPos = hit.point + (Vector3.up * spawnHeightOffset);
        } else {
            spawnPos = ray.origin + (ray.direction * 1.5f) + (Vector3.up * spawnHeightOffset);
        }

        obj.transform.position = spawnPos;
        obj.transform.rotation = Quaternion.identity;

        if (!originalPoses.ContainsKey(obj)) {
            originalPoses.Add(obj, new Pose(spawnPos, obj.transform.rotation));
            originalScales.Add(obj, obj.transform.localScale);
            detectedInThisSession.Add(obj);
        }

        obj.SetActive(true);
    }

    private void ReleaseToWorld(GameObject obj) {
        obj.transform.SetParent(null, true);
        Rigidbody rb = obj.GetComponent<Rigidbody>();
        if (rb != null) {
            rb.isKinematic = true;
            rb.useGravity = false;
        }

        MonoBehaviour[] scripts = obj.GetComponents<MonoBehaviour>();
        foreach (var s in scripts) {
            if (s.GetType().Name.Contains("ObjectManipulator")) {
                s.enabled = false;
                s.enabled = true;
            }
        }

        Collider col = obj.GetComponent<Collider>();
        if (col != null) { col.enabled = false; col.enabled = true; }
    }

    public void ClearBoxes() {
        foreach (var b in activeBoxes) {
            if (b != null) Destroy(b);
        }
        activeBoxes.Clear();
    }

    List<Detection> ParseDetections(Tensor<float> output) {
        List<Detection> detections = new List<Detection>();
        
        // Sentis Tensor access: Use output[batch, channel, index]
        int numAttributes = output.shape[1]; 
        int numBoxes = output.shape[2];      

        for (int i = 0; i < numBoxes; i++) {
            float maxScore = 0;
            int classIdx = 0;
            for (int c = 4; c < numAttributes; c++) {
                float score = output[0, c, i];
                if (score > maxScore) {
                    maxScore = score;
                    classIdx = c - 4;
                }
            }

            if (maxScore > scoreThreshold) {
                detections.Add(new Detection {
                    classIndex = classIdx,
                    score = maxScore,
                    // YOLO output is typically center_x, center_y, width, height
                    // Normalize by input size if the model doesn't already
                    rect = new Rect(output[0, 0, i] / inputWidth, output[0, 1, i] / inputHeight, 
                                    output[0, 2, i] / inputWidth, output[0, 3, i] / inputHeight)
                });
            }
        }
        return detections;
    }

    void OnDisable() {
        worker?.Dispose();
        if (webcamTexture != null) webcamTexture.Stop();
    }
}