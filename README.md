# 3D Object Renderer

A C++ program that renders different 3D objects (Cube, Sphere, Pyramid) with ASCII/text-based rendering.

## Features

- **3D Geometry Classes**: Vector3D and Matrix4x4 for 3D transformations
- **3D Objects**: Cube, Sphere, and Pyramid implementations
- **ASCII Renderer**: Text-based 3D rendering with depth buffering
- **Transformations**: Support for translation, rotation, and scaling
- **Unit Tests**: Comprehensive test suite using Google Test
- **CI/CD**: Automated builds and tests via GitHub Actions

## Building the Project

### Prerequisites

- CMake 3.14 or higher
- C++17 compatible compiler (g++, clang++)
- Build essentials

### Build Instructions

```bash
# Configure the project
cmake -B build -S .

# Build the project
cmake --build build

# Run the 3D renderer demo
./build/3d_renderer

# Run tests
cd build
ctest --output-on-failure
```

## Project Structure

```
.
├── include/          # Header files
│   ├── Vector3D.h
│   ├── Matrix4x4.h
│   ├── Object3D.h
│   └── Renderer.h
├── src/              # Source files
│   ├── Vector3D.cpp
│   ├── Matrix4x4.cpp
│   ├── Object3D.cpp
│   ├── Renderer.cpp
│   └── main.cpp
├── tests/            # Unit tests
│   ├── test_vector3d.cpp
│   ├── test_matrix4x4.cpp
│   ├── test_object3d.cpp
│   └── test_renderer.cpp
└── CMakeLists.txt
```

## Running Tests

The project includes comprehensive unit tests for all components:

```bash
# Build and run all tests
cmake --build build
cd build
ctest --verbose
```

## CI/CD

This project uses GitHub Actions for continuous integration. On every push and pull request:
- The code is automatically built
- All unit tests are executed
- The 3D renderer demo is run

See `.github/workflows/ci.yml` for the CI configuration.
