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
        public Transform targetTransform; // This is the 'Slot'
        public float entryOffset;
        public bool matchTargetScale; 

        [HideInInspector] public Vector3 scannedPos;
        [HideInInspector] public Quaternion scannedRot;
        [HideInInspector] public Vector3 scannedScale;
    }

    [Header("Sequence")]
    public List<AssemblyStep> steps;
    public int currentStepIndex = 0;

    [Header("Timing Settings")]
    public float flyToEntryDuration = 0.8f;
    public float slideToTargetDuration = 0.5f;
    public AnimationCurve movementCurve = AnimationCurve.EaseInOut(0, 0, 1, 1);

    private bool isMoving = false;

    // Called by DETECTOR once the scan is finished
    public void CaptureHomeState()
    {
        for (int i = 0; i < steps.Count; i++)
        {
            var step = steps[i];
            if (step.partToMove != null)
            {
                step.scannedPos = step.partToMove.transform.position;
                step.scannedRot = step.partToMove.transform.rotation;
                step.scannedScale = step.partToMove.transform.localScale;
                steps[i] = step;
            }
        }
        Debug.Log("Assembly Home States Saved.");
    }

    public void AssembleNext()
    {
        if (isMoving || currentStepIndex >= steps.Count) return;
        StartCoroutine(MoveRoutine(steps[currentStepIndex], true));
    }

    public void DisassemblePrevious()
    {
        if (isMoving || currentStepIndex <= 0) return;
        currentStepIndex--;
        StartCoroutine(MoveRoutine(steps[currentStepIndex], false));
    }

    private IEnumerator MoveRoutine(AssemblyStep step, bool assembling)
    {
        isMoving = true;
        GameObject part = step.partToMove;
        
        // Physics Safety
        Rigidbody rb = part.GetComponent<Rigidbody>();
        if (rb != null) rb.isKinematic = true;
        Collider col = part.GetComponent<Collider>();
        if (col != null) col.enabled = false; 

        // Define Start and End Points
        Vector3 startPos = part.transform.position;
        Quaternion startRot = part.transform.rotation;
        Vector3 startScale = part.transform.localScale;
        
        Vector3 finalPos = assembling ? step.targetTransform.position : step.scannedPos;
        Quaternion finalRot = assembling ? step.targetTransform.rotation : step.scannedRot;
        Vector3 finalScale = assembling ? (step.matchTargetScale ? step.targetTransform.localScale : startScale) : step.scannedScale;
        
        // L-Shape point (Relative to the target slot)
        Vector3 entryPoint = step.targetTransform.position + (step.targetTransform.up * step.entryOffset);

        if (assembling)
        {
            // FLY TO ENTRY -> SLIDE IN
            yield return LerpFull(part, startPos, entryPoint, startRot, finalRot, startScale, finalScale, flyToEntryDuration);
            yield return LerpFull(part, entryPoint, finalPos, finalRot, finalRot, finalScale, finalScale, slideToTargetDuration);
            currentStepIndex++;
        }
        else
        {
            // SLIDE OUT -> FLY HOME
            yield return LerpFull(part, startPos, entryPoint, startRot, startRot, startScale, startScale, slideToTargetDuration);
            yield return LerpFull(part, entryPoint, finalPos, startRot, finalRot, startScale, finalScale, flyToEntryDuration);
        }

        part.transform.position = finalPos;
        part.transform.rotation = finalRot;
        part.transform.localScale = finalScale;
        
        if (col != null) col.enabled = true;
        isMoving = false;
    }

    private IEnumerator LerpFull(GameObject obj, Vector3 p1, Vector3 p2, Quaternion r1, Quaternion r2, Vector3 s1, Vector3 s2, float duration)
    {
        float elapsed = 0;
        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            float t = movementCurve.Evaluate(elapsed / duration);
            obj.transform.position = Vector3.Lerp(p1, p2, t);
            obj.transform.rotation = Quaternion.Slerp(r1, r2, t);
            obj.transform.localScale = Vector3.Lerp(s1, s2, t);
            yield return null;
        }
    }
}