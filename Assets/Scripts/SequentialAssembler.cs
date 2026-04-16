using System.Collections.Generic;
using UnityEngine;
using System.Collections;

public class SequentialAssembler : MonoBehaviour
{
    [System.Serializable]
    public struct AssemblyStep
    {
        public string partName;
        public GameObject partToMove;
        public Transform targetTransform;
        public float entryOffset; // How high above the slot should it "pull up" first?
    }

    [Header("Sequence")]
    public List<AssemblyStep> steps;
    public int currentStepIndex = 0;

    [Header("Settings")]
    public float flyToEntryDuration = 0.8f;
    public float slideToTargetDuration = 0.5f;

    public void AssembleNextPart()
    {
        if (currentStepIndex < steps.Count)
        {
            StartCoroutine(ParkingRoutine(steps[currentStepIndex]));
            currentStepIndex++;
        }
    }

    private IEnumerator ParkingRoutine(AssemblyStep step)
    {
        if (step.partToMove == null || step.targetTransform == null) yield break;

        // --- PREP ---
        Rigidbody rb = step.partToMove.GetComponent<Rigidbody>();
        if (rb != null) rb.isKinematic = true;

        Vector3 startPos = step.partToMove.transform.position;
        Quaternion startRot = step.partToMove.transform.rotation;

        // CALCULATE ENTRY POINT (The "Driveway")
        // We move up along the target's 'up' axis by the entryOffset amount
        Vector3 entryPoint = step.targetTransform.position + (step.targetTransform.up * step.entryOffset);

        // --- STAGE 1: FLY TO ENTRY POINT ---
        float elapsed = 0;
        while (elapsed < flyToEntryDuration)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0, 1, elapsed / flyToEntryDuration);

            step.partToMove.transform.position = Vector3.Lerp(startPos, entryPoint, t);
            step.partToMove.transform.rotation = Quaternion.Lerp(startRot, step.targetTransform.rotation, t);
            yield return null;
        }

        // --- STAGE 2: SLIDE INTO PARKING SLOT ---
        elapsed = 0;
        while (elapsed < slideToTargetDuration)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0, 1, elapsed / slideToTargetDuration);

            step.partToMove.transform.position = Vector3.Lerp(entryPoint, step.targetTransform.position, t);
            yield return null;
        }

        // FINAL SNAP
        step.partToMove.transform.position = step.targetTransform.position;
        step.partToMove.transform.rotation = step.targetTransform.rotation;
    }

    public void ResetIndex() => currentStepIndex = 0;
}