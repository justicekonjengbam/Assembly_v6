using UnityEngine;

[RequireComponent(typeof(AudioSource))]
public class ButtonAudio : MonoBehaviour
{
    [Header("Audio Settings")]
    public AudioClip clickSound;
    [Range(0, 1)] public float volume = 1.0f;
    public bool playOnAwake = false;

    private AudioSource audioSource;

    void Awake()
    {
        audioSource = GetComponent<AudioSource>();
        
        // Configure the AudioSource automatically
        audioSource.playOnAwake = playOnAwake;
        audioSource.loop = false;
        audioSource.spatialBlend = 1.0f; // Set to 1.0 for 3D Spatial Sound on HoloLens
    }

    // --- CALL THIS FROM YOUR BUTTON ONCLICK ---
    public void PlayClick()
    {
        if (clickSound != null)
        {
            // PlayOneShot is better for buttons because it allows 
            // sounds to overlap if the user clicks rapidly.
            audioSource.PlayOneShot(clickSound, volume);
        }
        else
        {
            Debug.LogWarning("ButtonAudio: No AudioClip assigned!");
        }
    }

    // Optional: Play a specific clip if you have multiple sounds
    public void PlaySpecificSound(AudioClip clip)
    {
        if (clip != null)
        {
            audioSource.PlayOneShot(clip, volume);
        }
    }
}