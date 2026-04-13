using System.Collections.Generic;
using UnityEngine;
using Microsoft.MixedReality.OpenXR; // Required for ARMarkerManager

public class QRPlacer : MonoBehaviour
{
    [System.Serializable]
    public struct QRCodeMapping
    {
        [Tooltip("The exact text embedded inside the QR Code (e.g., 'Gear_01')")]
        public string qrText;
        public GameObject modelObject;
    }

    [Header("QR Mappings")]
    public List<QRCodeMapping> mappings;

    [Header("Dependencies")]
    [Tooltip("Drag the ARMarkerManager component here (usually on the XR Origin)")]
    public ARMarkerManager markerManager;

    private void Start()
    {
        // 1. Hide all mapped models at the start
        foreach (var map in mappings)
        {
            if (map.modelObject != null) map.modelObject.SetActive(false);
        }

        // 2. Auto-fetch the ARMarkerManager if the user forgot to drag it in
        if (markerManager == null)
        {
            markerManager = GetComponent<ARMarkerManager>();
        }

        // 3. Subscribe to the event
        if (markerManager != null)
        {
            markerManager.markersChanged += OnMarkersChanged;
            Debug.Log("SimpleQRPlacer is listening for QR codes...");
        }
        else
        {
            Debug.LogError("ARMarkerManager is missing! Please assign it.");
        }
    }

    private void OnMarkersChanged(ARMarkersChangedEventArgs args)
    {
        // Handle brand new markers
        foreach (var addedMarker in args.added)
        {
            ProcessMarker(addedMarker);
        }

        // Handle markers that moved (user shifted the paper)
        foreach (var updatedMarker in args.updated)
        {
            ProcessMarker(updatedMarker);
        }
    }

    private void ProcessMarker(ARMarker marker)
    {
        // 1. Decode the string embedded in the QR Code
        string decodedText = marker.GetDecodedString();
        
        if (string.IsNullOrEmpty(decodedText)) return;

        // Clean up the text to avoid matching errors (lowercase, remove extra spaces)
        string normalizedText = decodedText.Trim().ToLower();

        // 2. Match it with our list of structs
        foreach (var map in mappings)
        {
            if (map.qrText.Trim().ToLower() == normalizedText)
            {
                if (map.modelObject != null)
                {
                    // 3. Snap the 3D model exactly to the QR Code's physical position & rotation
                    map.modelObject.transform.position = marker.transform.position;
                    map.modelObject.transform.rotation = marker.transform.rotation;
                    
                    // NOTE: If your 3D models spawn facing flat into the table, uncomment the line below to stand them up:
                    // map.modelObject.transform.Rotate(90, 0, 0);

                    // 4. Turn the 3D model on
                    ForceActivate(map.modelObject);
                }
            }
        }
    }

    // Forces the assigned object AND its disabled parents to turn on
    void ForceActivate(GameObject obj)
    {
        Transform current = obj.transform;
        while (current != null)
        {
            current.gameObject.SetActive(true);
            current = current.parent;
        }
    }

    private void OnDestroy()
    {
        if (markerManager != null)
        {
            markerManager.markersChanged -= OnMarkersChanged;
        }
    }
}