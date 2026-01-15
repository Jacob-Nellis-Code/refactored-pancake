#include "Vector3D.h"
#include "Matrix4x4.h"
#include "Object3D.h"
#include "Renderer.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

void renderObject(Renderer& renderer, Object3D& object, const std::string& title) {
    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << title << "\n";
    std::cout << std::string(80, '=') << "\n";
    
    renderer.clear();
    renderer.render(object);
    std::cout << renderer.getOutput();
}

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " [OPTIONS]\n";
    std::cout << "\nOptions:\n";
    std::cout << "  --rotation-x <angle>   Rotation angle around X axis in degrees (default: 30)\n";
    std::cout << "  --rotation-y <angle>   Rotation angle around Y axis in degrees (default: 45)\n";
    std::cout << "  --rotation-z <angle>   Rotation angle around Z axis in degrees (default: 0)\n";
    std::cout << "  --help                 Display this help message\n";
    std::cout << "\nExample:\n";
    std::cout << "  " << programName << " --rotation-x 45 --rotation-y 90 --rotation-z 30\n";
}

int main(int argc, char* argv[]) {
    // Default rotation angles in degrees
    double rotationX = 30.0;
    double rotationY = 45.0;
    double rotationZ = 0.0;
    
    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            printUsage(argv[0]);
            return 0;
        } else if (strcmp(argv[i], "--rotation-x") == 0 && i + 1 < argc) {
            rotationX = std::atof(argv[++i]);
        } else if (strcmp(argv[i], "--rotation-y") == 0 && i + 1 < argc) {
            rotationY = std::atof(argv[++i]);
        } else if (strcmp(argv[i], "--rotation-z") == 0 && i + 1 < argc) {
            rotationZ = std::atof(argv[++i]);
        } else {
            std::cerr << "Unknown option: " << argv[i] << "\n";
            printUsage(argv[0]);
            return 1;
        }
    }
    
    // Convert degrees to radians
    double rotX = rotationX * M_PI / 180.0;
    double rotY = rotationY * M_PI / 180.0;
    double rotZ = rotationZ * M_PI / 180.0;
    
    std::cout << "3D Object Renderer Demo\n";
    std::cout << "========================\n";
    std::cout << "Rotation: X=" << rotationX << "° Y=" << rotationY << "° Z=" << rotationZ << "°\n";
    
    Renderer renderer(80, 24);
    
    // Create and render a Cube with custom rotation
    Cube cube(1.5);
    Matrix4x4 cubeTransform = Matrix4x4::rotationZ(rotZ) * 
                              Matrix4x4::rotationY(rotY) * 
                              Matrix4x4::rotationX(rotX);
    cube.transform(cubeTransform);
    renderObject(renderer, cube, "Cube (Custom Rotation)");
    
    // Create and render a Sphere
    Sphere sphere(1.0, 6);
    Matrix4x4 sphereTransform = Matrix4x4::translation(0, 0.5, 0);
    sphere.transform(sphereTransform);
    renderObject(renderer, sphere, "Sphere");
    
    // Create and render a Pyramid with custom rotation
    Pyramid pyramid(2.0, 1.5);
    Matrix4x4 pyramidTransform = Matrix4x4::rotationZ(rotZ * 0.5) *
                                  Matrix4x4::rotationY(rotY * 0.5) *
                                  Matrix4x4::rotationX(rotX * 0.5);
    pyramid.transform(pyramidTransform);
    renderObject(renderer, pyramid, "Pyramid (Custom Rotation)");
    
    // Create a scaled cube
    Cube smallCube(1.0);
    Matrix4x4 scaleTransform = Matrix4x4::scale(2.0, 0.5, 1.0) *
                               Matrix4x4::rotationZ(rotZ) *
                               Matrix4x4::rotationY(rotY) *
                               Matrix4x4::rotationX(rotX);
    smallCube.transform(scaleTransform);
    renderObject(renderer, smallCube, "Scaled and Rotated Cube");
    
    std::cout << "\nRendering complete!\n";
    return 0;
}
