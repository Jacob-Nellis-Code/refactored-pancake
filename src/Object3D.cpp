#include "Object3D.h"
#include <cmath>

Object3D::Object3D(const std::string& name) : name(name) {}

const std::vector<Vector3D>& Object3D::getVertices() const {
    return vertices;
}

const std::vector<Face>& Object3D::getFaces() const {
    return faces;
}

const std::string& Object3D::getName() const {
    return name;
}

void Object3D::transform(const Matrix4x4& matrix) {
    for (auto& vertex : vertices) {
        vertex = matrix * vertex;
    }
}

// Cube implementation
Cube::Cube(double size) : Object3D("Cube") {
    double half = size / 2.0;
    
    // Define 8 vertices of a cube
    vertices = {
        Vector3D(-half, -half, -half),  // 0
        Vector3D( half, -half, -half),  // 1
        Vector3D( half,  half, -half),  // 2
        Vector3D(-half,  half, -half),  // 3
        Vector3D(-half, -half,  half),  // 4
        Vector3D( half, -half,  half),  // 5
        Vector3D( half,  half,  half),  // 6
        Vector3D(-half,  half,  half)   // 7
    };
    
    // Define 6 faces (each face has 4 vertices)
    faces = {
        {{0, 1, 2, 3}},  // Front
        {{4, 5, 6, 7}},  // Back
        {{0, 1, 5, 4}},  // Bottom
        {{2, 3, 7, 6}},  // Top
        {{0, 3, 7, 4}},  // Left
        {{1, 2, 6, 5}}   // Right
    };
}

// Sphere implementation
Sphere::Sphere(double radius, int segments) : Object3D("Sphere") {
    // Create vertices using spherical coordinates
    for (int lat = 0; lat <= segments; lat++) {
        double theta = lat * M_PI / segments;
        double sinTheta = std::sin(theta);
        double cosTheta = std::cos(theta);
        
        for (int lon = 0; lon <= segments; lon++) {
            double phi = lon * 2 * M_PI / segments;
            double sinPhi = std::sin(phi);
            double cosPhi = std::cos(phi);
            
            double x = radius * cosPhi * sinTheta;
            double y = radius * cosTheta;
            double z = radius * sinPhi * sinTheta;
            
            vertices.push_back(Vector3D(x, y, z));
        }
    }
    
    // Create faces
    for (int lat = 0; lat < segments; lat++) {
        for (int lon = 0; lon < segments; lon++) {
            int first = lat * (segments + 1) + lon;
            int second = first + segments + 1;
            
            faces.push_back({{first, second, first + 1}});
            faces.push_back({{second, second + 1, first + 1}});
        }
    }
}

// Pyramid implementation
Pyramid::Pyramid(double baseSize, double height) : Object3D("Pyramid") {
    double half = baseSize / 2.0;
    
    // Define 5 vertices of a pyramid
    vertices = {
        Vector3D(-half, 0, -half),  // 0 - base corner
        Vector3D( half, 0, -half),  // 1 - base corner
        Vector3D( half, 0,  half),  // 2 - base corner
        Vector3D(-half, 0,  half),  // 3 - base corner
        Vector3D(0, height, 0)      // 4 - apex
    };
    
    // Define 5 faces
    faces = {
        {{0, 1, 2, 3}},  // Base
        {{0, 1, 4}},     // Front
        {{1, 2, 4}},     // Right
        {{2, 3, 4}},     // Back
        {{3, 0, 4}}      // Left
    };
}
