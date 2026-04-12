using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Unity.Sentis;
using System.Collections;
using TMPro; 

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

    [Header("UI References")]
    public RawImage displayImage; 
    public RectTransform boxContainer; 
    public GameObject boxPrefab; 
    public TextAsset classesFile; 
    public TMP_Text statusText; 
    
    [Header("Sequence UI")]
    public GameObject instructionCanvas; 
    public GameObject scanDisplayCanvas; 

    [Header("Detection Mapping")]
    public List<DetectionMapping> mappings;

    [Header("Settings")]
    [Tooltip("Increase this to 0.5 or 0.6 to stop phantom detections!")]
    [Range(0, 1)] public float scoreThreshold = 0.5f; 
    public int inputWidth = 640;
    public int inputHeight = 640;
    public bool flipY = true; 

    [Header("Continuous Scan Settings")]
    [Tooltip("How often to run the AI model in seconds. 1.0 = once per second.")]
    public float scanInterval = 1.0f; 

    [Header("3D Placement Settings")]
    [Tooltip("The layer your HoloLens Spatial Mesh is on (e.g., SpatialAwareness).")]
    public LayerMask spatialMeshLayer = ~0; 
    [Tooltip("Maximum distance to look for a surface (in meters).")]
    public float maxRaycastDistance = 3.0f;

    private Worker worker;
    private WebCamTexture webcamTexture;
    private RenderTexture renderTexture;
    private List<string> classNames = new List<string>();
    private List<GameObject> activeBoxes = new List<GameObject>();
    
    // Tracks if the continuous scan loop is running
    private bool isScanningContinuous = false; 
    private Coroutine scanCoroutine;

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
        
        if (instructionCanvas != null) instructionCanvas.SetActive(true);
        if (scanDisplayCanvas != null) scanDisplayCanvas.SetActive(false);
        if (statusText != null) statusText.text = "System Ready. Press Start to scan.";
    }

    // --- BUTTON TRIGGER: Call this to START the loop ---
    public void StartScanning() {
        if (isScanningContinuous) return; // Already scanning
        
        isScanningContinuous = true;
        
        if (instructionCanvas != null) instructionCanvas.SetActive(false);
        if (scanDisplayCanvas != null) scanDisplayCanvas.SetActive(true);
        if (statusText != null) statusText.text = "Scanning active...";

        scanCoroutine = StartCoroutine(ContinuousScanRoutine());
    }

    // --- BUTTON TRIGGER: Call this to STOP the loop ---
    public void StopScanning() {
        isScanningContinuous = false;
        
        if (scanCoroutine != null) {
            StopCoroutine(scanCoroutine);
            scanCoroutine = null;
        }

        if (instructionCanvas != null) instructionCanvas.SetActive(true);
        if (scanDisplayCanvas != null) scanDisplayCanvas.SetActive(false);
        if (statusText != null) statusText.text = "Scanning paused.";
        
        ClearBoxes();
    }

    public void ClearBoxes() {
        foreach (var b in activeBoxes) Destroy(b);
        activeBoxes.Clear();
    }

    // --- CONTINUOUS LOOP ---
    private IEnumerator ContinuousScanRoutine() {
        // Keep looping as long as the user hasn't pressed Stop
        while (isScanningContinuous) {
            
            // 1. Grab frame
            Graphics.Blit(webcamTexture, renderTexture);
            using Tensor<float> inputTensor = TextureConverter.ToTensor(renderTexture, inputWidth, inputHeight, 3);
            worker.Schedule(inputTensor);

            // 2. Wait for GPU
            yield return null; 

            // 3. Get results
            var output = worker.PeekOutput(outputName) as Tensor<float>;
            using var outputCPU = output.ReadbackAndClone(); 
            
            List<Detection> detections = ParseDetections(outputCPU);
            
            // 4. Update 2D and 3D UI
            UpdateUI(detections);
            ActivateMappedObjects(detections);

            if (statusText != null) {
                statusText.text = detections.Count > 0 ? $"Found {detections.Count} objects" : "Scanning...";
            }

            // 5. Wait for the designated interval (e.g., 1 second) before looping again
            yield return new WaitForSeconds(scanInterval);
        }
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
                t.text = $"{classNames[det.classIndex]}";
            }
        }
    }

    // --- RAYCAST TRIGGER ---
    void ActivateMappedObjects(List<Detection> detections) {
        foreach (var det in detections) {
            if (det.classIndex >= classNames.Count) continue;
            string detectedLabel = classNames[det.classIndex];

            foreach (var map in mappings) {
                if (map.labelInFile.Trim().ToLower() == detectedLabel) {
                    
                    if (map.modelObject != null) {
                        PlaceObjectIn3D(map.modelObject, det);
                    }
                   
                }
            }
        }
    }

    // --- 3D PLACEMENT LOGIC ---
    void PlaceObjectIn3D(GameObject obj, Detection det)
    {
        float centerX = det.rect.x + (det.rect.width / 2f);
        float centerY = det.rect.y + (det.rect.height / 2f);

        if (flipY) centerY = 1.0f - centerY;

        Ray ray = Camera.main.ViewportPointToRay(new Vector3(centerX, centerY, 0));

        if (Physics.Raycast(ray, out RaycastHit hit, maxRaycastDistance, spatialMeshLayer))
        {
            obj.transform.position = hit.point;
            obj.transform.up = hit.normal; 
            
            ForceActivate(obj);
        }
        else
        {
            // Spawn floating 1 meter away if no mesh is hit
            Vector3 floatingPosition = ray.origin + (ray.direction * 1.0f); 
            obj.transform.position = floatingPosition;
            
            ForceActivate(obj);
        }
    }

    void ForceActivate(GameObject obj) {
        Transform current = obj.transform;
        while (current != null) {
            current.gameObject.SetActive(true);
            current = current.parent;
        }
    }

    void OnDisable() {
        StopScanning();
        worker?.Dispose();
        if (webcamTexture != null) webcamTexture.Stop();
    }
}