using UnityEngine;
using MixedReality.Toolkit.UX;
using System.Linq; // for array operations

[RequireComponent(typeof(AudioSource))]
public class ButtonUnlock : MonoBehaviour
{
    public PressableButton[] buttons;
    public Renderer[] backplates;

    [Range(0f, 1f)]
    [Header("Live Transparency Control")]
    public float colorAlpha = 0.6f;

    [Header("Audio for Red Button")]
    public AudioClip redButtonSound;

    [Header("Reset Button (Optional)")]
    public PressableButton resetButton; // Drag reset button here

    ButtonState[] currentStates;
    AudioSource audioSource;

    const string SAVE_KEY = "ButtonUnlock_States"; // PlayerPrefs key

    static readonly Color LockedColor  = Color.red;
    static readonly Color ActiveColor  = Color.yellow;
    static readonly Color DoneColor    = Color.green;

    void Awake()
    {
        currentStates = new ButtonState[buttons.Length];
        audioSource = GetComponent<AudioSource>();

        foreach (var rend in backplates)
        {
            Material mat = rend.material;
            mat.SetFloat("_SrcBlend", (float)UnityEngine.Rendering.BlendMode.SrcAlpha);
            mat.SetFloat("_DstBlend", (float)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
        }
    }

    void Start()
    {
        // LOAD saved states across scenes
        LoadButtonStates();

        for (int i = 0; i < buttons.Length; i++)
        {
            int capturedIndex = i;
            buttons[i].OnClicked.AddListener(() => OnButtonPressed(capturedIndex));
        }

        // Reset button listener
        if (resetButton != null)
            resetButton.OnClicked.AddListener(ResetAll);

        // Apply current states
        for (int i = 0; i < buttons.Length; i++)
            SetButtonState(i, currentStates[i]);
    }

    void Update()
    {
        ApplyTransparencyToAll(colorAlpha);
    }

    void OnButtonPressed(int index)
    {
        if (currentStates[index] == ButtonState.Locked)
        {
            PlayRedButtonSound();
        }

        if (currentStates[index] != ButtonState.Active) return;
        CompleteButton(index);
    }

    void PlayRedButtonSound()
    {
        if (redButtonSound != null && audioSource != null)
        {
            audioSource.PlayOneShot(redButtonSound);
        }
    }

    void ApplyTransparencyToAll(float alpha)
    {
        for (int i = 0; i < backplates.Length; i++)
        {
            Material mat = backplates[i].material;
            mat.SetFloat("_Fade_Out_", alpha);
        }
    }

    public void CompleteButton(int index)
    {
        if (index < 0 || index >= buttons.Length) return;
        if (currentStates[index] == ButtonState.Done) return;

        SetButtonState(index, ButtonState.Done);

        int next = index + 1;
        if (next < buttons.Length)
            SetButtonState(next, ButtonState.Active);

        // SAVE after change
        SaveButtonStates();
    }

    void SetButtonState(int index, ButtonState state)
    {
        currentStates[index] = state;

        Collider col = buttons[index].GetComponentInChildren<Collider>();

        switch (state)
        {
            case ButtonState.Locked:
                if (col != null) col.enabled = false;
                break;
            case ButtonState.Active:
            case ButtonState.Done:
                if (col != null) col.enabled = true;
                break;
        }

        ApplyColor(index, GetColorForState(state));
    }

    void ApplyColor(int index, Color baseColor)
    {
        backplates[index].material.SetColor("_Base_Color_", baseColor);
    }

    Color GetColorForState(ButtonState state)
    {
        switch (state)
        {
            case ButtonState.Locked:  return LockedColor;
            case ButtonState.Active:  return ActiveColor;
            case ButtonState.Done:    return DoneColor;
            default:                  return Color.white;
        }
    }

    // SAVE button states to PlayerPrefs
    void SaveButtonStates()
    {
        string statesString = string.Join(",", currentStates.Select(s => (int)s));
        PlayerPrefs.SetString(SAVE_KEY, statesString);
        PlayerPrefs.Save(); // Force immediate save
    }

    // LOAD button states from PlayerPrefs - FIXED VERSION
    void LoadButtonStates()
    {
        if (PlayerPrefs.HasKey(SAVE_KEY))
        {
            string statesString = PlayerPrefs.GetString(SAVE_KEY);
            string[] statesArray = statesString.Split(',');
            
            for (int i = 0; i < Mathf.Min(currentStates.Length, statesArray.Length); i++)
            {
                if (int.TryParse(statesArray[i], out int stateInt))
                {
                    currentStates[i] = (ButtonState)stateInt;
                }
            }
        }
        else
        {
            // NO SAVED DATA = FRESH START: First button Active, others Locked
            if (buttons.Length > 0)
            {
                currentStates[0] = ButtonState.Active;
                for (int i = 1; i < currentStates.Length; i++)
                {
                    currentStates[i] = ButtonState.Locked;
                }
            }
        }
    }

    // RESET ALL buttons (called by reset button)
    public void ResetAll()
    {
        for (int i = 0; i < currentStates.Length; i++)
        {
            currentStates[i] = (i == 0) ? ButtonState.Active : ButtonState.Locked;
            SetButtonState(i, currentStates[i]);
        }
        SaveButtonStates();
    }

    void OnDestroy()
    {
        for (int i = 0; i < buttons.Length; i++)
            buttons[i].OnClicked.RemoveAllListeners();

        if (resetButton != null)
            resetButton.OnClicked.RemoveAllListeners();
    }

    enum ButtonState { Locked, Active, Done }
}
