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
    }

    [Header("Content List")]
    public List<DialogueStep> dialogueList;

    [Header("Auto Play")]
    public bool playOnStart = true;
    public int startIndex = 0; // CRITICAL: Set this to 0 in your Inspector

    [Header("References")]
    public AudioSource audioSource;
    public TMP_Text displayTMP;

    [Header("Settings")]
    [Tooltip("Time delay between words appearing")]
    public float wordSpeed = 0.25f;

    private Coroutine typingCoroutine;

    void Start()
    {
        // 1. Setup
        if (audioSource == null) audioSource = GetComponent<AudioSource>();
        if (displayTMP != null) displayTMP.text = "";

        // 2. Start initial dialogue
        if (playOnStart && dialogueList.Count > 0)
        {
            PlaySpecificIndex(startIndex);
        }
    }

    // Call this from your UI Buttons or other scripts
    public void PlaySpecificIndex(int index)
    {
        if (index >= 0 && index < dialogueList.Count)
        {
            StopAllAction();
            typingCoroutine = StartCoroutine(ExecuteStep(index));
        }
        else
        {
            Debug.LogWarning($"Index {index} is out of range! Your list starts at 0.");
        }
    }

    private IEnumerator ExecuteStep(int index)
    {
        // Wait one frame to ensure initialization is clean
        yield return null;

        // 1. Play Audio
        if (dialogueList[index].audioClip != null)
        {
            audioSource.clip = dialogueList[index].audioClip;
            audioSource.Play();
        }

        // 2. Word-by-Word Display
        string fullText = dialogueList[index].textContent;
        displayTMP.text = "";

        // Split by whitespace
        string[] words = fullText.Split(new[] { ' ', '\n', '\r' }, System.StringSplitOptions.RemoveEmptyEntries);

        for (int i = 0; i < words.Length; i++)
        {
            displayTMP.text += words[i] + " ";
            
            // Wait for the next word
            yield return new WaitForSeconds(wordSpeed);
        }
        
        typingCoroutine = null;
    }

    private void StopAllAction()
    {
        if (typingCoroutine != null) StopCoroutine(typingCoroutine);
        if (audioSource != null) audioSource.Stop();
    }

    // Call this if you want to clear the screen
    public void ClearDisplay()
    {
        StopAllAction();
        if (displayTMP != null) displayTMP.text = "";
    }
}