#include <gtest/gtest.h>
#include "Object3D.h"

TEST(Object3DTest, CubeCreation) {
    Cube cube(2.0);
    EXPECT_EQ(cube.getName(), "Cube");
    EXPECT_EQ(cube.getVertices().size(), 8);
    EXPECT_EQ(cube.getFaces().size(), 6);
}

TEST(Object3DTest, CubeVertices) {
    Cube cube(2.0);
    const auto& vertices = cube.getVertices();
    
    // Check that all vertices are at distance 1 from origin (for size 2.0)
    for (const auto& v : vertices) {
        EXPECT_DOUBLE_EQ(std::abs(v.x), 1.0);
        EXPECT_DOUBLE_EQ(std::abs(v.y), 1.0);
        EXPECT_DOUBLE_EQ(std::abs(v.z), 1.0);
    }
}

TEST(Object3DTest, SphereCreation) {
    Sphere sphere(1.0, 8);
    EXPECT_EQ(sphere.getName(), "Sphere");
    EXPECT_GT(sphere.getVertices().size(), 0);
    EXPECT_GT(sphere.getFaces().size(), 0);
}

TEST(Object3DTest, SphereRadius) {
    Sphere sphere(2.0, 8);
    const auto& vertices = sphere.getVertices();
    
    // Check that vertices are approximately at radius distance
    for (const auto& v : vertices) {
        double distance = v.magnitude();
        EXPECT_NEAR(distance, 2.0, 0.01);
    }
}

TEST(Object3DTest, PyramidCreation) {
    Pyramid pyramid(2.0, 1.5);
    EXPECT_EQ(pyramid.getName(), "Pyramid");
    EXPECT_EQ(pyramid.getVertices().size(), 5);
    EXPECT_EQ(pyramid.getFaces().size(), 5);
}

TEST(Object3DTest, PyramidApex) {
    Pyramid pyramid(2.0, 1.5);
    const auto& vertices = pyramid.getVertices();
    
    // The last vertex should be the apex
    const auto& apex = vertices[4];
    EXPECT_DOUBLE_EQ(apex.x, 0.0);
    EXPECT_DOUBLE_EQ(apex.y, 1.5);
    EXPECT_DOUBLE_EQ(apex.z, 0.0);
}

TEST(Object3DTest, Transform) {
    Cube cube(2.0);
    Matrix4x4 translation = Matrix4x4::translation(1.0, 2.0, 3.0);
    
    Vector3D firstVertexBefore = cube.getVertices()[0];
    cube.transform(translation);
    Vector3D firstVertexAfter = cube.getVertices()[0];
    
    EXPECT_DOUBLE_EQ(firstVertexAfter.x, firstVertexBefore.x + 1.0);
    EXPECT_DOUBLE_EQ(firstVertexAfter.y, firstVertexBefore.y + 2.0);
    EXPECT_DOUBLE_EQ(firstVertexAfter.z, firstVertexBefore.z + 3.0);
}

TEST(Object3DTest, CubeFaces) {
    Cube cube(1.0);
    const auto& faces = cube.getFaces();
    
    // Each face should have 4 vertices
    for (const auto& face : faces) {
        EXPECT_EQ(face.vertices.size(), 4);
    }
}

TEST(Object3DTest, PyramidFaces) {
    Pyramid pyramid(2.0, 1.0);
    const auto& faces = pyramid.getFaces();
    
    // Base should have 4 vertices, others should have 3
    EXPECT_EQ(faces[0].vertices.size(), 4);  // Base
    for (size_t i = 1; i < faces.size(); i++) {
        EXPECT_EQ(faces[i].vertices.size(), 3);  // Triangular faces
    }
}
