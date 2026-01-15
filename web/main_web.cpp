#include "Vector3D.h"
#include "Matrix4x4.h"
#include "Object3D.h"
#include "Renderer.h"
#include <iostream>
#include <cmath>
#include <string>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
#endif

// Static renderer instance to avoid repeated allocations during animation
static Renderer* g_renderer = nullptr;

void renderObject(Renderer& renderer, Object3D& object, const std::string& title) {
    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << title << "\n";
    std::cout << std::string(80, '=') << "\n";

    renderer.clear();
    renderer.render(object);
    std::cout << renderer.getOutput();
}

// Function to render a single frame with rotation
extern "C" {
    void renderFrame(double angleY) {
        // Initialize renderer on first call
        if (!g_renderer) {
            g_renderer = new Renderer(80, 24);
        }
        
        // Create and render a rotating Cube
        Cube cube(1.5);
        Matrix4x4 cubeTransform = Matrix4x4::rotationY(angleY) * 
                                  Matrix4x4::rotationX(angleY * 0.5);
        cube.transform(cubeTransform);
        renderObject(*g_renderer, cube, "Rotating Cube");
        
        // Create and render a Sphere with slight movement
        Sphere sphere(1.0, 6);
        Matrix4x4 sphereTransform = Matrix4x4::translation(0, 0.5, 0) *
                                    Matrix4x4::rotationY(angleY * 0.3);
        sphere.transform(sphereTransform);
        renderObject(*g_renderer, sphere, "Rotating Sphere");
        
        // Create and render a Pyramid
        Pyramid pyramid(2.0, 1.5);
        Matrix4x4 pyramidTransform = Matrix4x4::rotationY(-angleY * 0.7) *
                                      Matrix4x4::rotationX(angleY * 0.4);
        pyramid.transform(pyramidTransform);
        renderObject(*g_renderer, pyramid, "Rotating Pyramid");
    }
}

int main() {
    std::cout << "3D Object Renderer Demo\n";
    std::cout << "========================\n";
    std::cout << "Use the animation controls to see rotating 3D objects!\n";

    // Render initial frame at angle 0
    renderFrame(0.0);

    return 0;
}
