#include "Vector3D.h"
#include "Matrix4x4.h"
#include "Object3D.h"
#include "Renderer.h"
#include <iostream>
#include <cmath>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

void renderObject(Renderer& renderer, Object3D& object, const std::string& title) {
    std::cout << "\n" << std::string(80, '=') << "\n";
    std::cout << title << "\n";
    std::cout << std::string(80, '=') << "\n";

    renderer.clear();
    renderer.render(object);
    std::cout << renderer.getOutput();
}

int main() {
    std::cout << "3D Object Renderer Demo\n";
    std::cout << "========================\n";

    Renderer renderer(80, 24);

    // Create and render a Cube
    Cube cube(1.5);
    Matrix4x4 cubeTransform = Matrix4x4::rotationY(M_PI / 4) *
                              Matrix4x4::rotationX(M_PI / 6);
    cube.transform(cubeTransform);
    renderObject(renderer, cube, "Cube (Rotated)");

    // Create and render a Sphere
    Sphere sphere(1.0, 6);
    Matrix4x4 sphereTransform = Matrix4x4::translation(0, 0.5, 0);
    sphere.transform(sphereTransform);
    renderObject(renderer, sphere, "Sphere");

    // Create and render a Pyramid
    Pyramid pyramid(2.0, 1.5);
    Matrix4x4 pyramidTransform = Matrix4x4::rotationY(M_PI / 6) *
                                  Matrix4x4::rotationX(M_PI / 8);
    pyramid.transform(pyramidTransform);
    renderObject(renderer, pyramid, "Pyramid (Rotated)");

    // Create a scaled cube
    Cube smallCube(1.0);
    Matrix4x4 scaleTransform = Matrix4x4::scale(2.0, 0.5, 1.0) *
                               Matrix4x4::rotationZ(M_PI / 4);
    smallCube.transform(scaleTransform);
    renderObject(renderer, smallCube, "Scaled and Rotated Cube");

    std::cout << "\nRendering complete!\n";
    return 0;
}
