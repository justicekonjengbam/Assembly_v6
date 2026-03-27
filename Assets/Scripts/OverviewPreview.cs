using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OverviewPreview : MonoBehaviour
{
    [System.Serializable]
    public class PreviewStep
    {
        public string label;            // Name of the part (e.g., "Base")
        public GameObject targetObject;  // The actual 3D part
        public float delayBeforeAppear = 1.0f; // Time to wait before this one shows up
    }

    [Header("Sequence Settings")]
    public List<PreviewStep> previewSteps;
    public bool playOnStart = false;

    private Coroutine sequenceCoroutine;

    void Start()
    {
        // Hide everything at the very beginning
        ResetAll();

        if (playOnStart)
        {
            StartSequence();
        }
    }

    // --- CALL THIS FROM YOUR BUTTON ---
    public void StartSequence()
    {
        // Stop any sequence currently running so they don't overlap
        if (sequenceCoroutine != null) StopCoroutine(sequenceCoroutine);
        
        sequenceCoroutine = StartCoroutine(PlayPreviewRoutine());
    }

    private IEnumerator PlayPreviewRoutine()
    {
        // 1. Start by making sure everything is hidden
        ResetAll();

        // 2. Loop through the list
        foreach (var step in previewSteps)
        {
            // Wait for the specific interval time
            yield return new WaitForSeconds(step.delayBeforeAppear);

            if (step.targetObject != null)
            {
                step.targetObject.SetActive(true);
                Debug.Log($"Preview: Activated {step.label}");
            }
        }
        
        sequenceCoroutine = null;
    }

    // This turns everything OFF
    public void ResetAll()
    {
        if (sequenceCoroutine != null) StopCoroutine(sequenceCoroutine);
        
        foreach (var step in previewSteps)
        {
            if (step.targetObject != null)
            {
                step.targetObject.SetActive(false);
            }
        }
    }
}