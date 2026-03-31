using UnityEngine;
using UnityEngine.SceneManagement; // This is required for changing scenes!

public class SceneChanger : MonoBehaviour
{
    [Header("Scene Settings")]
    [Tooltip("Type the exact name of the scene you want to load here (Case Sensitive!).")]
    public string targetSceneName;

    // 1. USE THIS if you typed the name into the "Target Scene Name" box in the Inspector
    public void LoadConfiguredScene()
    {
        if (!string.IsNullOrEmpty(targetSceneName))
        {
            SceneManager.LoadScene(targetSceneName);
        }
        else
        {
            Debug.LogError("Scene Changer: You left the target scene name blank in the Inspector!");
        }
    }

    // 2. USE THIS if you want to type the scene name directly into the UI Button's OnClick event
    public void LoadSceneByName(string exactSceneName)
    {
        SceneManager.LoadScene(exactSceneName);
    }

    // 3. BONUS: Use this for a "Next" button. It just loads whatever scene is next in line.
    public void LoadNextScene()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(currentSceneIndex + 1);
    }

    // 4. BONUS: Use this for a "Restart" or "Reset" button.
    public void ReloadCurrentScene()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    // 5. BONUS: Use this for a "Quit" button
    public void QuitApp()
    {
        Debug.Log("Application Quitting!");
        Application.Quit();
    }
}