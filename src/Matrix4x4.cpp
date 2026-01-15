#include "Matrix4x4.h"
#include <cmath>
#include <cstring>

Matrix4x4::Matrix4x4() {
    std::memset(m, 0, sizeof(m));
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const {
    Matrix4x4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}

Vector3D Matrix4x4::operator*(const Vector3D& v) const {
    double x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3];
    double y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3];
    double z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3];
    double w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3];
    
    if (w != 0.0 && w != 1.0) {
        return Vector3D(x / w, y / w, z / w);
    }
    return Vector3D(x, y, z);
}

Matrix4x4 Matrix4x4::identity() {
    Matrix4x4 result;
    result.m[0][0] = 1; result.m[1][1] = 1;
    result.m[2][2] = 1; result.m[3][3] = 1;
    return result;
}

Matrix4x4 Matrix4x4::translation(double x, double y, double z) {
    Matrix4x4 result = identity();
    result.m[0][3] = x;
    result.m[1][3] = y;
    result.m[2][3] = z;
    return result;
}

Matrix4x4 Matrix4x4::rotationX(double angle) {
    Matrix4x4 result = identity();
    double c = std::cos(angle);
    double s = std::sin(angle);
    result.m[1][1] = c;  result.m[1][2] = -s;
    result.m[2][1] = s;  result.m[2][2] = c;
    return result;
}

Matrix4x4 Matrix4x4::rotationY(double angle) {
    Matrix4x4 result = identity();
    double c = std::cos(angle);
    double s = std::sin(angle);
    result.m[0][0] = c;   result.m[0][2] = s;
    result.m[2][0] = -s;  result.m[2][2] = c;
    return result;
}

Matrix4x4 Matrix4x4::rotationZ(double angle) {
    Matrix4x4 result = identity();
    double c = std::cos(angle);
    double s = std::sin(angle);
    result.m[0][0] = c;  result.m[0][1] = -s;
    result.m[1][0] = s;  result.m[1][1] = c;
    return result;
}

Matrix4x4 Matrix4x4::scale(double sx, double sy, double sz) {
    Matrix4x4 result = identity();
    result.m[0][0] = sx;
    result.m[1][1] = sy;
    result.m[2][2] = sz;
    return result;
}
