using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Unity.Sentis;
using System.Collections;
using TMPro; // Required for TextMeshPro

public class YOLOHoloLens : MonoBehaviour
{
    [Header("Model Settings")]
    public ModelAsset yoloModel;
    public string outputName = "output0"; 

    [Header("UI References")]
    public RawImage displayImage; 
    public RectTransform boxContainer; 
    public GameObject boxPrefab; 
    public TextAsset classesFile; 
    public TMP_Text statusText; // Updated to TMP_Text

    [Header("Settings")]
    [Range(0, 1)] public float scoreThreshold = 0.3f; 
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
                if (!string.IsNullOrWhiteSpace(line)) classNames.Add(line.Trim());
            }
        }

        if (WebCamTexture.devices.Length > 0) {
            webcamTexture = new WebCamTexture(640, 480);
            webcamTexture.Play();
            if (displayImage != null) displayImage.texture = webcamTexture;
        }

        renderTexture = new RenderTexture(inputWidth, inputHeight, 0, RenderTextureFormat.ARGB32);
        
        if (statusText != null) statusText.text = "System Ready";
    }

    public void Scan() {
        if (!isProcessing) StartCoroutine(RunInferenceRoutine());
    }

    // Optional: Clear boxes manually
    public void ClearBoxes() {
        foreach (var b in activeBoxes) Destroy(b);
        activeBoxes.Clear();
        if (statusText != null) statusText.text = "Cleared";
    }

    private IEnumerator RunInferenceRoutine() {
        isProcessing = true;
        
        if (statusText != null) statusText.text = "Scanning...";

        Graphics.Blit(webcamTexture, renderTexture);
        using Tensor<float> inputTensor = TextureConverter.ToTensor(renderTexture, inputWidth, inputHeight, 3);
        worker.Schedule(inputTensor);

        var output = worker.PeekOutput(outputName) as Tensor<float>;
        using var outputCPU = output.ReadbackAndClone(); 
        
        List<Detection> detections = ParseDetections(outputCPU);
        UpdateUI(detections);

        if (statusText != null) {
            statusText.text = detections.Count > 0 ? $"Found {detections.Count} objects" : "No objects detected";
        }

        isProcessing = false;
        yield return null;
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
        foreach (var b in activeBoxes) Destroy(b);
        activeBoxes.Clear();

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

            // UPDATED FOR TMP
            TMP_Text t = go.GetComponentInChildren<TMP_Text>();
            if (t != null) {
                string name = (det.classIndex < classNames.Count) ? classNames[det.classIndex] : $"ID {det.classIndex}";
                t.text = $"{name} ({det.score:P0})";
            }
        }
    }

    public void Quit() => Application.Quit();

    void OnDisable() {
        worker?.Dispose();
        if (webcamTexture != null) webcamTexture.Stop();
    }
}