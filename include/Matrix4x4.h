#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "Vector3D.h"

class Matrix4x4 {
public:
    double m[4][4];
    
    Matrix4x4();
    
    // Matrix operations
    Matrix4x4 operator*(const Matrix4x4& other) const;
    Vector3D operator*(const Vector3D& v) const;
    
    // Create transformation matrices
    static Matrix4x4 identity();
    static Matrix4x4 translation(double x, double y, double z);
    static Matrix4x4 rotationX(double angle);
    static Matrix4x4 rotationY(double angle);
    static Matrix4x4 rotationZ(double angle);
    static Matrix4x4 scale(double sx, double sy, double sz);
};

#endif // MATRIX4X4_H
