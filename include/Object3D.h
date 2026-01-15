#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "Vector3D.h"
#include "Matrix4x4.h"
#include <vector>
#include <string>

struct Face {
    std::vector<int> vertices;
};

class Object3D {
protected:
    std::vector<Vector3D> vertices;
    std::vector<Face> faces;
    std::string name;
    
public:
    Object3D(const std::string& name);
    virtual ~Object3D() = default;
    
    const std::vector<Vector3D>& getVertices() const;
    const std::vector<Face>& getFaces() const;
    const std::string& getName() const;
    
    void transform(const Matrix4x4& matrix);
};

class Cube : public Object3D {
public:
    Cube(double size = 1.0);
};

class Sphere : public Object3D {
public:
    Sphere(double radius = 1.0, int segments = 8);
};

class Pyramid : public Object3D {
public:
    Pyramid(double baseSize = 1.0, double height = 1.0);
};

#endif // OBJECT3D_H
