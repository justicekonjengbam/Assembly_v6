using System.Collections.Generic;
using UnityEngine;
using Unity.Sentis;
using System.Collections;
using TMPro;
using UnityEngine.UI;
using UnityEngine.XR.ARFoundation; 
using UnityEngine.XR.ARSubsystems;

public class YOLO : MonoBehaviour
{
    [System.Serializable]
    public struct DetectionMapping {
        public string labelName;       // Exactly as it appears in labels.txt
        public GameObject infoPrefab;  // The 3D model/label to spawn
    }

    [Header("Diagnostics UI")]
    public TMP_Text statusText;       
    public RawImage cameraPreview;    

    [Header("Model Settings")]
    public ModelAsset yoloModel;
    public string outputName = "output0"; 
    [Range(0, 1)] public float scoreThreshold = 0.5f;

    [Header("Timed Scan Settings")]
    public float scanDuration = 5.0f; 
    public float scanFrequency = 0.2f; // 5 scans per second during the burst

    [Header("3D Setup")]
    public LayerMask spatialMeshLayer = 31; 
    public List<DetectionMapping> mappings;
    public TextAsset classesFile;
    
    private Worker worker;
    private WebCamTexture webcam;
    private List<string> classNames = new List<string>();
    private bool isScanning = false;

    void Awake() {
        if (statusText != null) statusText.text = "System Initializing...";
    }

    void Start() {
        if (yoloModel == null) { LogStatus("Error: No Model Asset!"); return; }
        
        // Setup Sentis
        worker = new Worker(ModelLoader.Load(yoloModel), BackendType.GPUCompute);

        // Load Labels
        if (classesFile != null) {
            foreach (var line in classesFile.text.Split('\n')) {
                if (!string.IsNullOrWhiteSpace(line)) classNames.Add(line.Trim().ToLower());
            }
        }

        // Setup Camera
        if (WebCamTexture.devices.Length > 0) {
            webcam = new WebCamTexture(640, 640); 
            webcam.Play();
            if (cameraPreview != null) cameraPreview.texture = webcam;
            LogStatus("Ready to Scan");
        } else {
            LogStatus("Error: No Camera!");
        }
    }

    // Call this from your UI Button
    public void StartTimedScan() {
        if (!isScanning && webcam != null) {
            StartCoroutine(TimedScanRoutine());
        }
    }

    private IEnumerator TimedScanRoutine() {
        isScanning = true;
        float timer = 0;

        while (timer < scanDuration) {
            LogStatus($"Scanning... {Mathf.Ceil(scanDuration - timer)}s");

            using Tensor<float> inputTensor = TextureConverter.ToTensor(webcam, 640, 640, 3);
            worker.Schedule(inputTensor);

            yield return new WaitForEndOfFrame();

            var output = worker.PeekOutput(outputName) as Tensor<float>;
            using var outputCPU = output.ReadbackAndClone();

            ParseAndPlace(outputCPU);

            yield return new WaitForSeconds(scanFrequency);
            timer += scanFrequency;
        }

        LogStatus("Scan Finished");
        isScanning = false;
    }

    void ParseAndPlace(Tensor<float> output) {
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
                float normX = output[0, 0, i] / 640f;
                float normY = 1.0f - (output[0, 1, i] / 640f); 
                Spawn3DInstruction(classIdx, new Vector2(normX, normY), maxScore);
            }
        }
    }

    void Spawn3DInstruction(int classIdx, Vector2 viewportPos, float score) {
        if (classIdx >= classNames.Count) return;
        string label = classNames[classIdx];
        var map = mappings.Find(m => m.labelName.ToLower() == label.ToLower());
        
        if (map.infoPrefab != null) {
            Ray ray = Camera.main.ViewportPointToRay(new Vector3(viewportPos.x, viewportPos.y, 0));
            
            if (Physics.Raycast(ray, out RaycastHit hit, 5.0f, spatialMeshLayer)) {
                
                // Prevent duplicate spawns within 10cm of each other
                if (IsPositionOccupied(hit.point)) return;

                GameObject inst = Instantiate(map.infoPrefab, hit.point, Quaternion.identity);
                inst.tag = "DetectionLabel"; // MUST create this tag in Unity
                
                // Attach World Anchor
                inst.AddComponent<ARAnchor>();
                
                // Optional: Show Name and Confidence
                TMP_Text textComp = inst.GetComponentInChildren<TMP_Text>();
                if (textComp != null) textComp.text = $"{label} {Mathf.RoundToInt(score * 100)}%";

                inst.transform.LookAt(Camera.main.transform);
                inst.transform.Rotate(0, 180, 0); 
            }
        }
    }

    bool IsPositionOccupied(Vector3 pos) {
        Collider[] colliders = Physics.OverlapSphere(pos, 0.1f);
        foreach (var col in colliders) {
            if (col.CompareTag("DetectionLabel")) return true;
        }
        return false;
    }

    public void ClearAllLabels() {
        GameObject[] labels = GameObject.FindGameObjectsWithTag("DetectionLabel");
        foreach (var l in labels) Destroy(l);
        LogStatus("Labels Cleared");
    }

    void LogStatus(string msg) {
        if (statusText != null) statusText.text = msg;
    }

    void OnDestroy() {
        worker?.Dispose();
        webcam?.Stop();
    }
}