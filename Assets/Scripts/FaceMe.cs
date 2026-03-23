using UnityEngine;

public class FaceMe : MonoBehaviour
{
    private Transform mainCameraTransform;

    [Header("Correction Settings")]
    [Tooltip("If the wrong side is facing you, try (0, 180, 0) or (90, 0, 0)")]
    public Vector3 rotationOffset = new Vector3(0, 180, 0); 

    void Start()
    {
        if (Camera.main != null)
        {
            mainCameraTransform = Camera.main.transform;
        }
    }

    void LateUpdate()
    {
        if (mainCameraTransform == null) return;

        // 1. Make the object look at the camera
        transform.LookAt(mainCameraTransform);

        // 2. Apply the offset to flip it to the "correct" side
        transform.Rotate(rotationOffset);
    }
}