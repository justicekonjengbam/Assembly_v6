using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class AudioText : MonoBehaviour
{
    [System.Serializable]
    public struct DialogueStep
    {
        public string label; 
        public AudioClip audioClip;
        [TextArea(3, 10)]
        public string textContent;
        public TMP_Text specificDisplay; 
    }

    [Header("Content List")]
    public List<DialogueStep> dialogueList;

    [Header("Auto Play")]
    public bool playOnStart = true;
    public int startIndex = 0; 

    [Header("Global References")]
    public AudioSource audioSource;
    public TMP_Text globalDisplayTMP;

    [Header("Settings")]
    public float wordSpeed = 0.25f;

    private Coroutine typingCoroutine;

    void Start()
    {
        if (audioSource == null) audioSource = GetComponent<AudioSource>();
        if (globalDisplayTMP != null) globalDisplayTMP.text = "";

        if (playOnStart && dialogueList.Count > 0)
        {
            PlaySpecificIndex(startIndex);
        }
    }

    // --- NEW FUNCTION: CALL THIS TO KILL THE SOUND AND TEXT IMMEDIATELY ---
    public void StopAndClear()
    {
        // 1. Stop the typewriter effect immediately
        if (typingCoroutine != null)
        {
            StopCoroutine(typingCoroutine);
            typingCoroutine = null;
        }

        // 2. Stop the audio
        if (audioSource != null)
        {
            audioSource.Stop();
            audioSource.clip = null; // Clears the loaded clip
        }

        // 3. Clear the text displays
        if (globalDisplayTMP != null) globalDisplayTMP.text = "";
        
        foreach(var step in dialogueList)
        {
            if (step.specificDisplay != null) step.specificDisplay.text = "";
        }

        Debug.Log("Audio and Text stopped for menu transition.");
    }

    public void PlaySpecificIndex(int index)
    {
        if (index >= 0 && index < dialogueList.Count)
        {
            // We call StopAndClear internally to ensure no overlap
            StopAndClear();
            typingCoroutine = StartCoroutine(ExecuteStep(index));
        }
    }

    private IEnumerator ExecuteStep(int index)
    {
        yield return null;

        TMP_Text targetDisplay = dialogueList[index].specificDisplay != null 
                                 ? dialogueList[index].specificDisplay 
                                 : globalDisplayTMP;

        if (targetDisplay == null) yield break;

        if (dialogueList[index].audioClip != null)
        {
            audioSource.clip = dialogueList[index].audioClip;
            audioSource.Play();
        }

        string fullText = dialogueList[index].textContent;
        targetDisplay.text = "";

        string[] words = fullText.Split(new[] { ' ', '\n', '\r' }, System.StringSplitOptions.RemoveEmptyEntries);

        for (int i = 0; i < words.Length; i++)
        {
            targetDisplay.text += words[i] + " ";
            yield return new WaitForSeconds(wordSpeed);
        }
        
        typingCoroutine = null;
    }
}