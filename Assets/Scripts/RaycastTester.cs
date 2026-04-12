using UnityEngine;

public class RaycastTester : MonoBehaviour
{
    [Header("Testing Setup")]
    [Tooltip("Create a small 3D Sphere in your scene and drag it here.")]
    public Transform hitMarker; 
    
    [Tooltip("Make sure this matches the Layer of your Spatial Mesh prefab!")]
    public LayerMask spatialMeshLayer = ~0; 
    
    public float maxDistance = 5.0f;

    void Update()
    {
        // Safety check
        if (hitMarker == null || Camera.main == null) return;

        // Shoot a ray directly forward from the center of the HoloLens camera
        Ray ray = new Ray(Camera.main.transform.position, Camera.main.transform.forward);

        // Perform the Raycast
        if (Physics.Raycast(ray, out RaycastHit hit, maxDistance, spatialMeshLayer))
        {
            // We hit the mesh! 
            hitMarker.gameObject.SetActive(true);
            
            // Move our test sphere to the exact hit point
            hitMarker.position = hit.point;
            
            // Optional: Rotate the sphere so its "up" matches the surface angle (great for testing table flatness)
            hitMarker.up = hit.normal; 

            // Draw a line in the Unity Editor Scene view so you can see it on your PC
            Debug.DrawLine(ray.origin, hit.point, Color.green);
        }
        else
        {
            // We are looking into empty space, hide the marker
            hitMarker.gameObject.SetActive(false);
            
            Debug.DrawRay(ray.origin, ray.direction * maxDistance, Color.red);
        }
    }
}