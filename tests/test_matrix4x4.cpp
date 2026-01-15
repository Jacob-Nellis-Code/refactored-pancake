#include <gtest/gtest.h>
#include "Matrix4x4.h"
#include <cmath>

TEST(Matrix4x4Test, Identity) {
    Matrix4x4 m = Matrix4x4::identity();
    EXPECT_DOUBLE_EQ(m.m[0][0], 1.0);
    EXPECT_DOUBLE_EQ(m.m[1][1], 1.0);
    EXPECT_DOUBLE_EQ(m.m[2][2], 1.0);
    EXPECT_DOUBLE_EQ(m.m[3][3], 1.0);
    EXPECT_DOUBLE_EQ(m.m[0][1], 0.0);
    EXPECT_DOUBLE_EQ(m.m[1][0], 0.0);
}

TEST(Matrix4x4Test, Translation) {
    Matrix4x4 m = Matrix4x4::translation(1.0, 2.0, 3.0);
    Vector3D v(0.0, 0.0, 0.0);
    Vector3D result = m * v;
    EXPECT_DOUBLE_EQ(result.x, 1.0);
    EXPECT_DOUBLE_EQ(result.y, 2.0);
    EXPECT_DOUBLE_EQ(result.z, 3.0);
}

TEST(Matrix4x4Test, RotationX) {
    Matrix4x4 m = Matrix4x4::rotationX(M_PI / 2);  // 90 degrees
    Vector3D v(0.0, 1.0, 0.0);
    Vector3D result = m * v;
    EXPECT_NEAR(result.x, 0.0, 1e-9);
    EXPECT_NEAR(result.y, 0.0, 1e-9);
    EXPECT_NEAR(result.z, 1.0, 1e-9);
}

TEST(Matrix4x4Test, RotationY) {
    Matrix4x4 m = Matrix4x4::rotationY(M_PI / 2);  // 90 degrees
    Vector3D v(1.0, 0.0, 0.0);
    Vector3D result = m * v;
    EXPECT_NEAR(result.x, 0.0, 1e-9);
    EXPECT_NEAR(result.y, 0.0, 1e-9);
    EXPECT_NEAR(result.z, -1.0, 1e-9);
}

TEST(Matrix4x4Test, RotationZ) {
    Matrix4x4 m = Matrix4x4::rotationZ(M_PI / 2);  // 90 degrees
    Vector3D v(1.0, 0.0, 0.0);
    Vector3D result = m * v;
    EXPECT_NEAR(result.x, 0.0, 1e-9);
    EXPECT_NEAR(result.y, 1.0, 1e-9);
    EXPECT_NEAR(result.z, 0.0, 1e-9);
}

TEST(Matrix4x4Test, Scale) {
    Matrix4x4 m = Matrix4x4::scale(2.0, 3.0, 4.0);
    Vector3D v(1.0, 1.0, 1.0);
    Vector3D result = m * v;
    EXPECT_DOUBLE_EQ(result.x, 2.0);
    EXPECT_DOUBLE_EQ(result.y, 3.0);
    EXPECT_DOUBLE_EQ(result.z, 4.0);
}

TEST(Matrix4x4Test, MatrixMultiplication) {
    Matrix4x4 m1 = Matrix4x4::translation(1.0, 0.0, 0.0);
    Matrix4x4 m2 = Matrix4x4::scale(2.0, 2.0, 2.0);
    Matrix4x4 result = m1 * m2;
    
    Vector3D v(1.0, 1.0, 1.0);
    Vector3D transformed = result * v;
    EXPECT_DOUBLE_EQ(transformed.x, 3.0);  // scaled then translated
    EXPECT_DOUBLE_EQ(transformed.y, 2.0);
    EXPECT_DOUBLE_EQ(transformed.z, 2.0);
}

TEST(Matrix4x4Test, CombinedTransformations) {
    Matrix4x4 translate = Matrix4x4::translation(1.0, 2.0, 3.0);
    Matrix4x4 scale = Matrix4x4::scale(2.0, 2.0, 2.0);
    Matrix4x4 combined = translate * scale;
    
    Vector3D v(1.0, 1.0, 1.0);
    Vector3D result = combined * v;
    EXPECT_DOUBLE_EQ(result.x, 3.0);
    EXPECT_DOUBLE_EQ(result.y, 4.0);
    EXPECT_DOUBLE_EQ(result.z, 5.0);
}
