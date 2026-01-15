#ifndef RENDERER_H
#define RENDERER_H

#include "Object3D.h"
#include <string>
#include <vector>

class Renderer {
private:
    int width;
    int height;
    std::vector<std::vector<char>> buffer;
    std::vector<std::vector<double>> depthBuffer;
    
    void clearBuffers();
    void plotPoint(int x, int y, char c, double depth);
    
public:
    Renderer(int width = 80, int height = 24);
    
    void render(const Object3D& object);
    std::string getOutput() const;
    void clear();
};

#endif // RENDERER_H
