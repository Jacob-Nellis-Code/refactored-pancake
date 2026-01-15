#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

class Vector3D {
public:
    double x, y, z;
    
    Vector3D();
    Vector3D(double x, double y, double z);
    
    // Vector operations
    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(double scalar) const;
    Vector3D operator/(double scalar) const;
    
    // Dot product
    double dot(const Vector3D& other) const;
    
    // Cross product
    Vector3D cross(const Vector3D& other) const;
    
    // Magnitude
    double magnitude() const;
    
    // Normalize
    Vector3D normalize() const;
    
    // Equality
    bool operator==(const Vector3D& other) const;
};

std::ostream& operator<<(std::ostream& os, const Vector3D& v);

#endif // VECTOR3D_H
