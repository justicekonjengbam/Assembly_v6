using System.Collections.Generic;
using UnityEngine;
using Microsoft.MixedReality.OpenXR;
using System.Collections;

public class QRPlacer : MonoBehaviour
{
    [System.Serializable]
    public struct QRCodeMapping
    {
        public string qrText;
        public GameObject modelObject; 
    }

    [Header("QR Mappings")]
    public List<QRCodeMapping> mappings;

    [Header("Dependencies")]
    public ARMarkerManager markerManager;

    [Header("Scan Settings")]
    public float scanDuration = 5.0f;
    public float verticalOffset = 0.1f; 

    private bool isScanning = false;
    private HashSet<GameObject> detectedInThisSession = new HashSet<GameObject>();
    
    // Dictionary to store the original spawn position/rotation/scale for resetting
    private Dictionary<GameObject, Pose> originalPoses = new Dictionary<GameObject, Pose>();
    private Dictionary<GameObject, Vector3> originalScales = new Dictionary<GameObject, Vector3>();

    private void Start()
    {
        foreach (var map in mappings)
        {
            if (map.modelObject != null) map.modelObject.SetActive(false);
        }
        if (markerManager == null) markerManager = GetComponent<ARMarkerManager>();
    }

    // --- FUNCTION 1: RESET POSITION & SCALE ---
    // Link this to your "Reset" button
    public void ResetScaleAndPosition()
    {
        foreach (var obj in detectedInThisSession)
        {
            if (obj != null && originalPoses.ContainsKey(obj))
            {
                obj.transform.position = originalPoses[obj].position;
                obj.transform.rotation = originalPoses[obj].rotation;
                obj.transform.localScale = originalScales[obj];
                
                // Reset velocity if it has a Rigidbody
                Rigidbody rb = obj.GetComponent<Rigidbody>();
                if (rb != null)
                {
                    rb.velocity = Vector3.zero;
                    rb.angularVelocity = Vector3.zero;
                }
            }
        }
    }

    // --- FUNCTION 2: REMOVE OBJECTS ---
    // Link this to your "Remove" button
    public void RemoveAllObjects()
    {
        foreach (var obj in detectedInThisSession)
        {
            if (obj != null) obj.SetActive(false);
        }
        detectedInThisSession.Clear();
        originalPoses.Clear();
        originalScales.Clear();
    }

    public void StartScanSequence()
    {
        if (isScanning) return;
        StartCoroutine(TimedQRScanRoutine());
    }

    private IEnumerator TimedQRScanRoutine()
    {
        isScanning = true;
        if (markerManager != null) markerManager.markersChanged += OnMarkersChanged;
        yield return new WaitForSeconds(scanDuration);
        if (markerManager != null) markerManager.markersChanged -= OnMarkersChanged;

        foreach (var obj in detectedInThisSession)
        {
            ReleaseToWorld(obj);
        }
        isScanning = false;
    }

    private void OnMarkersChanged(ARMarkersChangedEventArgs args)
    {
        if (!isScanning) return;
        foreach (var marker in args.added) ProcessMarker(marker);
        foreach (var marker in args.updated) ProcessMarker(marker);
    }

    private void ProcessMarker(ARMarker marker)
    {
        string decodedText = marker.GetDecodedString();
        if (string.IsNullOrEmpty(decodedText)) return;
        string normalizedText = decodedText.Trim().ToLower();

        foreach (var map in mappings)
        {
            if (map.qrText.Trim().ToLower() == normalizedText)
            {
                if (map.modelObject != null)
                {
                    Vector3 spawnPos = marker.transform.position + (Vector3.up * verticalOffset);
                    Quaternion spawnRot = marker.transform.rotation;

                    map.modelObject.transform.SetParent(null, true);
                    map.modelObject.transform.position = spawnPos;
                    map.modelObject.transform.rotation = spawnRot;
                    
                    if (!map.modelObject.activeSelf)
                    {
                        map.modelObject.SetActive(true);
                        detectedInThisSession.Add(map.modelObject);
                        
                        // Save the initial spawn state for the Reset function
                        if (!originalPoses.ContainsKey(map.modelObject))
                        {
                            originalPoses.Add(map.modelObject, new Pose(spawnPos, spawnRot));
                            originalScales.Add(map.modelObject, map.modelObject.transform.localScale);
                        }
                    }
                }
            }
        }
    }

    private void ReleaseToWorld(GameObject obj)
    {
        obj.transform.SetParent(null, true);
        Rigidbody rb = obj.GetComponent<Rigidbody>();
        if (rb != null)
        {
            rb.isKinematic = true;
            rb.useGravity = false;
        }

        MonoBehaviour[] scripts = obj.GetComponents<MonoBehaviour>();
        foreach (var s in scripts)
        {
            if (s.GetType().Name.Contains("ObjectManipulator"))
            {
                s.enabled = false;
                s.enabled = true;
            }
        }

        Collider col = obj.GetComponent<Collider>();
        if (col != null) { col.enabled = false; col.enabled = true; }
    }

    private void OnDestroy()
    {
        if (markerManager != null) markerManager.markersChanged -= OnMarkersChanged;
    }
}