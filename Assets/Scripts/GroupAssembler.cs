using System.Collections.Generic;
using UnityEngine;
using System.Collections;

public class GroupAssembler : MonoBehaviour
{
    [System.Serializable]
    public struct PartConfig {
        public string partName; 
        public GameObject part;       
        public Transform target;     
        public float speed; 
        public float entryOffset; 
        public bool matchTargetScale; 
    }

    [System.Serializable]
    public struct AssemblyStep {
        public string stepName;
        public List<PartConfig> partsInStep; 
    }

    public List<AssemblyStep> steps;
    public int currentStepIndex = 0;
    private Dictionary<GameObject, Pose> homePoses = new Dictionary<GameObject, Pose>();
    private Dictionary<GameObject, Vector3> homeScales = new Dictionary<GameObject, Vector3>();
    private bool isRunning = false;

    public void CaptureHomeState() {
        homePoses.Clear();
        homeScales.Clear();
        foreach (var s in steps) {
            foreach (var c in s.partsInStep) {
                if (c.part != null && !homePoses.ContainsKey(c.part)) {
                    homePoses[c.part] = new Pose(c.part.transform.position, c.part.transform.rotation);
                    homeScales[c.part] = c.part.transform.localScale;
                }
            }
        }
    }

    public void AssembleNext() {
        if (isRunning || currentStepIndex >= steps.Count) return;
        StartCoroutine(MoveStep(steps[currentStepIndex], false));
        currentStepIndex++;
    }

    public void ReverseLast() {
        if (isRunning || currentStepIndex <= 0) return;
        currentStepIndex--;
        StartCoroutine(MoveStep(steps[currentStepIndex], true));
    }

    private IEnumerator MoveStep(AssemblyStep step, bool rev) {
        isRunning = true;
        float max = 0;
        foreach (var p in step.partsInStep) if (p.speed > max) max = p.speed;
        foreach (var c in step.partsInStep) StartCoroutine(Animate(c, rev));
        yield return new WaitForSeconds(max + 0.1f);
        isRunning = false;
    }

    private IEnumerator Animate(PartConfig c, bool rev) {
        if (c.part == null || !homePoses.ContainsKey(c.part)) yield break;
        
        Vector3 eP = rev ? homePoses[c.part].position : c.target.position;
        Quaternion eR = rev ? homePoses[c.part].rotation : c.target.rotation;
        Vector3 eS = rev ? homeScales[c.part] : (c.matchTargetScale ? c.target.localScale : c.part.transform.localScale);
        
        Vector3 entry = c.target.position + (c.target.up * c.entryOffset);
        float elapsed = 0;
        Vector3 sP = c.part.transform.position;
        Quaternion sR = c.part.transform.rotation;
        Vector3 sS = c.part.transform.localScale;

        while (elapsed < c.speed) {
            elapsed += Time.deltaTime;
            float t = Mathf.SmoothStep(0, 1, elapsed / c.speed);
            Vector3 targetPath = (elapsed < c.speed * 0.5f) ? entry : eP;
            c.part.transform.position = Vector3.Lerp(sP, targetPath, t);
            c.part.transform.rotation = Quaternion.Slerp(sR, eR, t);
            c.part.transform.localScale = Vector3.Lerp(sS, eS, t);
            yield return null;
        }
        c.part.transform.position = eP;
    }
}