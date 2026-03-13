// YOLO.cs
// Unity Sentis YOLO overlay with console + on-screen labels.

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Unity.Sentis;

public class YOLO : MonoBehaviour
{
    [Header("Model Settings")]
    public ModelAsset yoloModel;
    public string inputName = "images";
    public string outputName = "output0";

    [Header("Camera & UI")]
    public RawImage displayImage;
    public Color boxColor = Color.green;
    public float scoreThreshold = 0.4f;
    public float nmsThreshold = 0.45f;

    [Header("YOLO Input")]
    public int inputWidth = 640;
    public int inputHeight = 640;
    public TextAsset classesFile;   // labels.txt, one per line

    [Header("Debug")]
    public bool logDetections = true;

    private Worker worker;
    private WebCamTexture webcamTexture;
    private Texture2D camTexture2D;
    private List<string> classNames = new List<string>();

    private struct Detection
    {
        public int classIndex;
        public float score;
        public Rect rect;   // normalized [0,1], top-left in model space
    }

    private List<Detection> latestDetections = new List<Detection>();
    private Texture2D lineTex;

    void Start()
    {
        if (yoloModel == null)
        {
            Debug.LogError("YOLO: Please assign a Sentis ModelAsset.");
            return;
        }

        var runtimeModel = ModelLoader.Load(yoloModel);
        worker = new Worker(runtimeModel, BackendType.GPUCompute);

        if (classesFile != null)
        {
            foreach (var line in classesFile.text.Split('\n'))
            {
                var t = line.Trim();
                if (!string.IsNullOrEmpty(t))
                    classNames.Add(t);
            }
        }

        if (WebCamTexture.devices.Length == 0)
        {
            Debug.LogError("YOLO: No camera devices found.");
            return;
        }

        var dev = WebCamTexture.devices[0];
        webcamTexture = new WebCamTexture(dev.name);
        webcamTexture.Play();

        if (displayImage != null)
        {
            displayImage.texture = webcamTexture;
            // RawImage RectTransform should stretch full screen, no AspectRatioFitter.
        }
    }

    void OnDisable()
    {
        if (worker != null) worker.Dispose();
        if (webcamTexture != null && webcamTexture.isPlaying) webcamTexture.Stop();
    }

    void Update()
    {
        if (webcamTexture == null || !webcamTexture.isPlaying)
            return;

        RunYOLO();
    }

    void RunYOLO()
    {
        if (webcamTexture.width <= 16 || webcamTexture.height <= 16)
            return;

        if (camTexture2D == null ||
            camTexture2D.width != webcamTexture.width ||
            camTexture2D.height != webcamTexture.height)
        {
            camTexture2D = new Texture2D(webcamTexture.width, webcamTexture.height, TextureFormat.RGB24, false);
        }

        camTexture2D.SetPixels(webcamTexture.GetPixels());
        camTexture2D.Apply();

        Texture2D resized = ResizeTexture(camTexture2D, inputWidth, inputHeight);

        using (Tensor<float> inputTensor = TextureConverter.ToTensor(resized, inputWidth, inputHeight, 3))
        {
            worker.Schedule(new Tensor[] { inputTensor });
        }

        Destroy(resized);

        using (Tensor outputGPU = worker.PeekOutput(outputName))
        using (Tensor<float> output = outputGPU.ReadbackAndClone() as Tensor<float>)
        {
            if (output != null)
                latestDetections = ParseDetectionsPixelsToNormalized(output, scoreThreshold, nmsThreshold);
        }

        if (logDetections)
        {
            foreach (var d in latestDetections)
            {
                string label = GetLabel(d.classIndex);
                Debug.Log($"YOLO DETECT: label={label}, score={d.score:0.00}, rect(norm)={d.rect}");
            }
        }
    }

    Texture2D ResizeTexture(Texture2D source, int width, int height)
    {
        RenderTexture rt = RenderTexture.GetTemporary(width, height, 0, RenderTextureFormat.ARGB32);
        RenderTexture prev = RenderTexture.active;

        Graphics.Blit(source, rt);
        RenderTexture.active = rt;

        Texture2D tex = new Texture2D(width, height, TextureFormat.RGB24, false);
        tex.ReadPixels(new Rect(0, 0, width, height), 0, 0);
        tex.Apply();

        RenderTexture.active = prev;
        RenderTexture.ReleaseTemporary(rt);
        return tex;
    }

    // Model outputs x,y,w,h in pixels (center-based) in 640x640
    List<Detection> ParseDetectionsPixelsToNormalized(Tensor<float> output, float scoreThresh, float nmsThresh)
    {
        List<Detection> detections = new List<Detection>();

        var shape = output.shape; // [1, numBoxes, numValues]
        int numBoxes = shape[1];
        int numValues = shape[2];

        for (int i = 0; i < numBoxes; i++)
        {
            float xCenterPx = output[0, i, 0];
            float yCenterPx = output[0, i, 1];
            float wPx = output[0, i, 2];
            float hPx = output[0, i, 3];
            float obj = output[0, i, 4];

            int bestClass = -1;
            float bestScore = 0f;
            for (int c = 5; c < numValues; c++)
            {
                float clsScore = output[0, i, c];
                if (clsScore > bestScore)
                {
                    bestScore = clsScore;
                    bestClass = c - 5;
                }
            }

            float score = obj * bestScore;
            if (score < scoreThresh)
                continue;

            float wNorm = wPx / inputWidth;
            float hNorm = hPx / inputHeight;
            float xCenterNorm = xCenterPx / inputWidth;
            float yCenterNorm = yCenterPx / inputHeight;

            float xMinNorm = xCenterNorm - wNorm / 2f;
            float yMinNorm = yCenterNorm - hNorm / 2f;

            Rect rectNorm = new Rect(xMinNorm, yMinNorm, wNorm, hNorm);
            detections.Add(new Detection
            {
                classIndex = bestClass,
                score = score,
                rect = rectNorm
            });
        }

        // NMS
        detections.Sort((a, b) => b.score.CompareTo(a.score));
        List<Detection> result = new List<Detection>();

        while (detections.Count > 0)
        {
            Detection best = detections[0];
            result.Add(best);
            detections.RemoveAt(0);

            for (int i = detections.Count - 1; i >= 0; i--)
            {
                if (IoU(best.rect, detections[i].rect) > nmsThreshold)
                    detections.RemoveAt(i);
            }
        }

        return result;
    }

    float IoU(Rect a, Rect b)
    {
        float x1 = Mathf.Max(a.xMin, b.xMin);
        float y1 = Mathf.Max(a.yMin, b.yMin);
        float x2 = Mathf.Min(a.xMax, b.xMax);
        float y2 = Mathf.Min(a.yMax, b.yMax);

        float inter = Mathf.Max(0, x2 - x1) * Mathf.Max(0, y2 - y1);
        float union = a.width * a.height + b.width * b.height - inter;
        if (union <= 0) return 0;
        return inter / union;
    }

    string GetLabel(int classIndex)
    {
        if (classIndex >= 0 && classIndex < classNames.Count)
            return classNames[classIndex];
        return "class_" + classIndex;
    }

    void OnGUI()
    {
        if (displayImage == null || latestDetections == null || webcamTexture == null)
            return;

        // Full RawImage rect
        Rect fullRect = GetRawImageScreenRect(displayImage);

        // Actual video rect (handles grey bars)
        float videoAspect = (float)webcamTexture.width / webcamTexture.height;
        float uiAspect = fullRect.width / fullRect.height;

        Rect videoRect = fullRect;

        if (uiAspect > videoAspect)
        {
            float targetWidth = fullRect.height * videoAspect;
            float padX = (fullRect.width - targetWidth) * 0.5f;
            videoRect = new Rect(fullRect.x + padX, fullRect.y, targetWidth, fullRect.height);
        }
        else if (uiAspect < videoAspect)
        {
            float targetHeight = fullRect.width / videoAspect;
            float padY = (fullRect.height - targetHeight) * 0.5f;
            videoRect = new Rect(fullRect.x, fullRect.y + padY, fullRect.width, targetHeight);
        }

        foreach (var det in latestDetections)
        {
            float x = videoRect.x + det.rect.x * videoRect.width;
            float y = videoRect.y + det.rect.y * videoRect.height;
            float w = det.rect.width * videoRect.width;
            float h = det.rect.height * videoRect.height;

            Rect box = new Rect(x, y, w, h);
            DrawRect(box, 2, boxColor);

            string label = GetLabel(det.classIndex) + " " + det.score.ToString("0.00");
            GUI.color = Color.black;
            GUI.Label(new Rect(box.x, box.y - 18, 250, 18), label);
        }
    }

    Rect GetRawImageScreenRect(RawImage img)
    {
        Vector3[] corners = new Vector3[4];
        img.rectTransform.GetWorldCorners(corners);

        Vector2 min = RectTransformUtility.WorldToScreenPoint(null, corners[0]);
        Vector2 max = RectTransformUtility.WorldToScreenPoint(null, corners[2]);

        float x = min.x;
        float y = Screen.height - max.y;
        float w = max.x - min.x;
        float h = max.y - min.y;

        return new Rect(x, y, w, h);
    }

    void DrawRect(Rect rect, int thickness, Color color)
    {
        if (lineTex == null)
            lineTex = new Texture2D(1, 1);

        lineTex.SetPixel(0, 0, color);
        lineTex.Apply();

        GUI.DrawTexture(new Rect(rect.x, rect.y, rect.width, thickness), lineTex);
        GUI.DrawTexture(new Rect(rect.x, rect.y, thickness, rect.height), lineTex);
        GUI.DrawTexture(new Rect(rect.x + rect.width - thickness, rect.y, thickness, rect.height), lineTex);
        GUI.DrawTexture(new Rect(rect.x, rect.y + rect.height - thickness, rect.width, thickness), lineTex);
    }
}
