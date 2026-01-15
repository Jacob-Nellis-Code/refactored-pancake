#include <gtest/gtest.h>
#include "Vector3D.h"
#include <cmath>

TEST(Vector3DTest, DefaultConstructor) {
    Vector3D v;
    EXPECT_DOUBLE_EQ(v.x, 0.0);
    EXPECT_DOUBLE_EQ(v.y, 0.0);
    EXPECT_DOUBLE_EQ(v.z, 0.0);
}

TEST(Vector3DTest, ParameterizedConstructor) {
    Vector3D v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v.x, 1.0);
    EXPECT_DOUBLE_EQ(v.y, 2.0);
    EXPECT_DOUBLE_EQ(v.z, 3.0);
}

TEST(Vector3DTest, Addition) {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    Vector3D result = v1 + v2;
    EXPECT_DOUBLE_EQ(result.x, 5.0);
    EXPECT_DOUBLE_EQ(result.y, 7.0);
    EXPECT_DOUBLE_EQ(result.z, 9.0);
}

TEST(Vector3DTest, Subtraction) {
    Vector3D v1(4.0, 5.0, 6.0);
    Vector3D v2(1.0, 2.0, 3.0);
    Vector3D result = v1 - v2;
    EXPECT_DOUBLE_EQ(result.x, 3.0);
    EXPECT_DOUBLE_EQ(result.y, 3.0);
    EXPECT_DOUBLE_EQ(result.z, 3.0);
}

TEST(Vector3DTest, ScalarMultiplication) {
    Vector3D v(1.0, 2.0, 3.0);
    Vector3D result = v * 2.0;
    EXPECT_DOUBLE_EQ(result.x, 2.0);
    EXPECT_DOUBLE_EQ(result.y, 4.0);
    EXPECT_DOUBLE_EQ(result.z, 6.0);
}

TEST(Vector3DTest, ScalarDivision) {
    Vector3D v(2.0, 4.0, 6.0);
    Vector3D result = v / 2.0;
    EXPECT_DOUBLE_EQ(result.x, 1.0);
    EXPECT_DOUBLE_EQ(result.y, 2.0);
    EXPECT_DOUBLE_EQ(result.z, 3.0);
}

TEST(Vector3DTest, DotProduct) {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    double result = v1.dot(v2);
    EXPECT_DOUBLE_EQ(result, 32.0);  // 1*4 + 2*5 + 3*6 = 32
}

TEST(Vector3DTest, CrossProduct) {
    Vector3D v1(1.0, 0.0, 0.0);
    Vector3D v2(0.0, 1.0, 0.0);
    Vector3D result = v1.cross(v2);
    EXPECT_DOUBLE_EQ(result.x, 0.0);
    EXPECT_DOUBLE_EQ(result.y, 0.0);
    EXPECT_DOUBLE_EQ(result.z, 1.0);
}

TEST(Vector3DTest, Magnitude) {
    Vector3D v(3.0, 4.0, 0.0);
    EXPECT_DOUBLE_EQ(v.magnitude(), 5.0);
}

TEST(Vector3DTest, Normalize) {
    Vector3D v(3.0, 4.0, 0.0);
    Vector3D result = v.normalize();
    EXPECT_DOUBLE_EQ(result.x, 0.6);
    EXPECT_DOUBLE_EQ(result.y, 0.8);
    EXPECT_DOUBLE_EQ(result.z, 0.0);
    EXPECT_NEAR(result.magnitude(), 1.0, 1e-9);
}

TEST(Vector3DTest, Equality) {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(1.0, 2.0, 3.0);
    Vector3D v3(1.0, 2.0, 3.1);
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
}
