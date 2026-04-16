using System.Collections.Generic;
using UnityEngine;
using System.Collections;

public class GroupAssembler : MonoBehaviour
{
    [System.Serializable]
    public struct AssemblyGroup
    {
        public string stepName;
        public GameObject[] partsInThisStep;    // Multiple parts can go here
        public Transform[] targetsInThisStep;  // Must match the order of parts
        public float entryOffset;               // Prevents phasing for this group
    }

    [Header("Sequence Configuration")]
    public List<AssemblyGroup> assemblySteps;
    public int currentStepIndex = 0;

    [Header("Animation Settings")]
    public float flyDuration = 1.2f;

    private Dictionary<GameObject, Pose> initialPoses = new Dictionary<GameObject, Pose>();

    void Start()
    {
        // Save the very first positions so we can always "Reset"
        foreach (var step in assemblySteps)
        {
            foreach (var part in step.partsInThisStep)
            {
                if (part != null && !initialPoses.ContainsKey(part))
                    initialPoses.Add(part, new Pose(part.transform.position, part.transform.rotation));
            }
        }
    }

    // --- FORWARD: Assemble the next group ---
    public void AssembleNextGroup()
    {
        if (currentStepIndex < assemblySteps.Count)
        {
            StartCoroutine(AnimateGroup(assemblySteps[currentStepIndex], false));
            currentStepIndex++;
        }
    }

    // --- REVERSE: Disassemble the last group ---
    public void ReverseLastGroup()
    {
        if (currentStepIndex > 0)
        {
            currentStepIndex--;
            StartCoroutine(AnimateGroup(assemblySteps[currentStepIndex], true));
        }
    }

    // --- RESET: Teleport everything back to start ---
    public void ResetAll()
    {
        StopAllCoroutines();
        currentStepIndex = 0;
        foreach (var kvp in initialPoses)
        {
            kvp.Key.transform.position = kvp.Value.position;
            kvp.Key.transform.rotation = kvp.Value.rotation;
            Rigidbody rb = kvp.Key.GetComponent<Rigidbody>();
            if (rb != null) { rb.velocity = Vector3.zero; rb.isKinematic = true; }
        }
    }

    private IEnumerator AnimateGroup(AssemblyGroup group, bool isReverse)
    {
        float elapsed = 0;
        int count = group.partsInThisStep.Length;
        
        Vector3[] startPos = new Vector3[count];
        Quaternion[] startRot = new Quaternion[count];
        Vector3[] endPos = new Vector3[count];
        Quaternion[] endRot = new Quaternion[count];
        Vector3[] entryPoints = new Vector3[count];

        // Setup coordinates for all parts in the group
        for (int i = 0; i < count; i++)
        {
            GameObject part = group.partsInThisStep[i];
            Transform target = group.targetsInThisStep[i];

            startPos[i] = part.transform.position;
            startRot[i] = part.transform.rotation;
            
            // If reversing, the end is the original scan pose. If forward, it's the target.
            endPos[i] = isReverse ? initialPoses[part].position : target.position;
            endRot[i] = isReverse ? initialPoses[part].rotation : target.rotation;

            // Calculate "Driveway" entry point to prevent phasing
            Vector3 direction = isReverse ? part.transform.up : target.up;
            entryPoints[i] = (isReverse ? startPos[i] : endPos[i]) + (direction * group.entryOffset);

            Rigidbody rb = part.GetComponent<Rigidbody>();
            if (rb != null) rb.isKinematic = true;
        }

        // STAGE 1: Fly to entry points (Parking alignment)
        while (elapsed < flyDuration * 0.6f)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0, 1, elapsed / (flyDuration * 0.6f));

            for (int i = 0; i < count; i++)
            {
                group.partsInThisStep[i].transform.position = Vector3.Lerp(startPos[i], entryPoints[i], t);
                group.partsInThisStep[i].transform.rotation = Quaternion.Lerp(startRot[i], endRot[i], t);
            }
            yield return null;
        }

        // STAGE 2: Slide into final slot
        elapsed = 0;
        while (elapsed < flyDuration * 0.4f)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0, 1, elapsed / (flyDuration * 0.4f));

            for (int i = 0; i < count; i++)
            {
                group.partsInThisStep[i].transform.position = Vector3.Lerp(entryPoints[i], endPos[i], t);
            }
            yield return null;
        }
    }
}