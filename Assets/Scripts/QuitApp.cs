using UnityEngine;

public class QuitApp : MonoBehaviour
{
    // --- CALL THIS FROM YOUR UI BUTTON ---
    public void ExitGame()
    {
        Debug.Log("Exiting Application...");

        // This part handles the Unity Editor
        #if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
        #else
            // This part handles the actual HoloLens / Windows Build
            Application.Quit();
        #endif
    }
}