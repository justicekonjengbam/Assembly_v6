using System.Collections.Generic;
using UnityEngine;
using Microsoft.MixedReality.OpenXR; 
using System.Collections;

public class QRPlacer : MonoBehaviour
{
    public GroupAssembler assembler;
    public ARMarkerManager markerManager;
    
    [System.Serializable]
    public struct QRKitMapping {
        public string qrText;
        public List<GameObject> partPrefabs; 
    }
    public List<QRKitMapping> mappings;

    public float scanDuration = 5.0f;
    public float verticalGap = 0.01f;
    [HideInInspector] public bool isScanning = false; 
    private bool isPlaced = false;

    public void StartScanning() {
        if (isScanning) return;
        StartCoroutine(ScanTimer());
    }

    private IEnumerator ScanTimer() {
        isScanning = true;
        isPlaced = false;
        yield return new WaitForSeconds(scanDuration);
        isScanning = false;
    }

    private void Start() {
        if (markerManager != null) markerManager.markersChanged += OnMarkersChanged;
    }

    private void OnMarkersChanged(ARMarkersChangedEventArgs args) {
        if (!isScanning || isPlaced) return;
        foreach (var m in args.added) ProcessMarker(m);
        foreach (var m in args.updated) ProcessMarker(m);
    }

    private void ProcessMarker(ARMarker marker) {
        string txt = marker.GetDecodedString()?.Trim().ToLower();
        if (string.IsNullOrEmpty(txt)) return;

        foreach (var map in mappings) {
            if (map.qrText.Trim().ToLower() == txt) {
                isPlaced = true;
                isScanning = false;
                SpawnKit(map, marker.transform);
                if (assembler != null) assembler.CaptureHomeState();
                break;
            }
        }
    }

    private void SpawnKit(QRKitMapping kit, Transform mTrans) {
        float yOff = 0;
        foreach (GameObject prefab in kit.partPrefabs) {
            if (prefab == null) continue;
            GameObject obj = Instantiate(prefab);
            
            float h = 0.02f;
            var r = obj.GetComponentInChildren<Renderer>();
            if (r != null) h = r.bounds.size.y;

            obj.transform.position = mTrans.position + (Vector3.up * (yOff + verticalGap));
            obj.transform.rotation = mTrans.rotation;
            yOff += h + verticalGap;

            if (obj.GetComponent<Rigidbody>()) obj.GetComponent<Rigidbody>().isKinematic = true;

            // AGGRESSIVE FILL: Just find the next empty slot in the assembler
            FillNextAvailableSlot(obj);
        }
    }

    private void FillNextAvailableSlot(GameObject obj) {
        if (assembler == null) return;
        foreach (var step in assembler.steps) {
            for (int i = 0; i < step.partsInStep.Count; i++) {
                if (step.partsInStep[i].part == null) {
                    var config = step.partsInStep[i];
                    config.part = obj;
                    step.partsInStep[i] = config;
                    return; // Assigned!
                }
            }
        }
    }
}