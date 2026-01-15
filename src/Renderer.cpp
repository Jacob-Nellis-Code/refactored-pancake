#include "Renderer.h"
#include <algorithm>
#include <sstream>
#include <cmath>

Renderer::Renderer(int width, int height) 
    : width(width), height(height) {
    buffer.resize(height, std::vector<char>(width, ' '));
    depthBuffer.resize(height, std::vector<double>(width, -1e9));
}

void Renderer::clearBuffers() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            buffer[y][x] = ' ';
            depthBuffer[y][x] = -1e9;
        }
    }
}

void Renderer::plotPoint(int x, int y, char c, double depth) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        if (depth > depthBuffer[y][x]) {
            buffer[y][x] = c;
            depthBuffer[y][x] = depth;
        }
    }
}

void Renderer::render(const Object3D& object) {
    const auto& vertices = object.getVertices();
    const auto& faces = object.getFaces();
    
    // Project 3D vertices to 2D screen coordinates
    std::vector<std::pair<int, int>> projected;
    for (const auto& v : vertices) {
        // Simple orthographic projection with scaling
        int x = static_cast<int>((v.x + 2.0) * width / 4.0);
        int y = static_cast<int>((v.y + 2.0) * height / 4.0);
        projected.push_back({x, y});
    }
    
    // Draw edges of each face
    for (const auto& face : faces) {
        for (size_t i = 0; i < face.vertices.size(); i++) {
            int v1 = face.vertices[i];
            int v2 = face.vertices[(i + 1) % face.vertices.size()];
            
            if (v1 < static_cast<int>(vertices.size()) && 
                v2 < static_cast<int>(vertices.size())) {
                
                int x1 = projected[v1].first;
                int y1 = projected[v1].second;
                int x2 = projected[v2].first;
                int y2 = projected[v2].second;
                
                // Draw line using Bresenham's algorithm
                int dx = std::abs(x2 - x1);
                int dy = std::abs(y2 - y1);
                int sx = x1 < x2 ? 1 : -1;
                int sy = y1 < y2 ? 1 : -1;
                int err = dx - dy;
                
                int x = x1, y = y1;
                double depth = vertices[v1].z;
                
                while (true) {
                    plotPoint(x, y, '*', depth);
                    
                    if (x == x2 && y == y2) break;
                    
                    int e2 = 2 * err;
                    if (e2 > -dy) {
                        err -= dy;
                        x += sx;
                    }
                    if (e2 < dx) {
                        err += dx;
                        y += sy;
                    }
                }
            }
        }
    }
    
    // Draw vertices as points
    for (size_t i = 0; i < vertices.size(); i++) {
        int x = projected[i].first;
        int y = projected[i].second;
        plotPoint(x, y, 'o', vertices[i].z);
    }
}

std::string Renderer::getOutput() const {
    std::stringstream ss;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ss << buffer[y][x];
        }
        ss << '\n';
    }
    return ss.str();
}

void Renderer::clear() {
    clearBuffers();
}
