#include <gtest/gtest.h>
#include "Renderer.h"
#include "Object3D.h"

TEST(RendererTest, Creation) {
    Renderer renderer(80, 24);
    std::string output = renderer.getOutput();
    EXPECT_FALSE(output.empty());
}

TEST(RendererTest, OutputSize) {
    int width = 80;
    int height = 24;
    Renderer renderer(width, height);
    std::string output = renderer.getOutput();
    
    // Count newlines
    int lineCount = 0;
    for (char c : output) {
        if (c == '\n') lineCount++;
    }
    EXPECT_EQ(lineCount, height);
}

TEST(RendererTest, RenderCube) {
    Renderer renderer(80, 24);
    Cube cube(1.0);
    
    renderer.render(cube);
    std::string output = renderer.getOutput();
    
    // Output should contain some non-space characters
    bool hasContent = false;
    for (char c : output) {
        if (c != ' ' && c != '\n') {
            hasContent = true;
            break;
        }
    }
    EXPECT_TRUE(hasContent);
}

TEST(RendererTest, RenderSphere) {
    Renderer renderer(80, 24);
    Sphere sphere(1.0, 6);
    
    renderer.render(sphere);
    std::string output = renderer.getOutput();
    
    // Output should contain some rendered characters
    bool hasContent = false;
    for (char c : output) {
        if (c != ' ' && c != '\n') {
            hasContent = true;
            break;
        }
    }
    EXPECT_TRUE(hasContent);
}

TEST(RendererTest, RenderPyramid) {
    Renderer renderer(80, 24);
    Pyramid pyramid(1.0, 1.0);
    
    renderer.render(pyramid);
    std::string output = renderer.getOutput();
    
    // Output should contain some rendered characters
    bool hasContent = false;
    for (char c : output) {
        if (c != ' ' && c != '\n') {
            hasContent = true;
            break;
        }
    }
    EXPECT_TRUE(hasContent);
}

TEST(RendererTest, Clear) {
    Renderer renderer(80, 24);
    Cube cube(1.0);
    
    renderer.render(cube);
    std::string output1 = renderer.getOutput();
    
    renderer.clear();
    std::string output2 = renderer.getOutput();
    
    // After clearing, should have less content
    int nonSpace1 = 0, nonSpace2 = 0;
    for (char c : output1) if (c != ' ' && c != '\n') nonSpace1++;
    for (char c : output2) if (c != ' ' && c != '\n') nonSpace2++;
    
    EXPECT_LT(nonSpace2, nonSpace1);
}

TEST(RendererTest, MultipleRenders) {
    Renderer renderer(80, 24);
    Cube cube(1.0);
    Sphere sphere(1.0, 6);
    
    renderer.render(cube);
    std::string output1 = renderer.getOutput();
    
    renderer.clear();
    renderer.render(sphere);
    std::string output2 = renderer.getOutput();
    
    // Both should have content
    EXPECT_FALSE(output1.empty());
    EXPECT_FALSE(output2.empty());
}
