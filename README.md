# 3D Object Renderer

A C++ program that renders different 3D objects (Cube, Sphere, Pyramid) with ASCII/text-based rendering.

**[Try the live WebAssembly demo with real-time animation!](https://jacob-nellis-code.github.io/refactored-pancake/)**

## Features

- **3D Geometry Classes**: Vector3D and Matrix4x4 for 3D transformations
- **3D Objects**: Cube, Sphere, and Pyramid implementations
- **ASCII Renderer**: Text-based 3D rendering with depth buffering
- **Transformations**: Support for translation, rotation, and scaling
- **CLI Arguments**: Customize rotation angles via command-line options
- **Web Animation**: Interactive demo with real-time rotating 3D objects
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

# Run the 3D renderer demo (with default rotation)
./build/3d_renderer

# Run with custom rotation angles (in degrees)
./build/3d_renderer --rotation-x 45 --rotation-y 90 --rotation-z 30

# View help for CLI options
./build/3d_renderer --help

# Run tests
cd build
ctest --output-on-failure
```

## CLI Usage

The 3D renderer supports command-line arguments to customize the rotation of objects:

```bash
./build/3d_renderer [OPTIONS]

Options:
  --rotation-x <angle>   Rotation angle around X axis in degrees (default: 30)
  --rotation-y <angle>   Rotation angle around Y axis in degrees (default: 45)
  --rotation-z <angle>   Rotation angle around Z axis in degrees (default: 0)
  --help                 Display help message

Example:
  ./build/3d_renderer --rotation-x 90 --rotation-y 0 --rotation-z 45
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

## Web Version

A WebAssembly version of this renderer is available that runs directly in your browser! The C++ code is compiled to WebAssembly using Emscripten and automatically deployed to GitHub Pages.

**[Launch Web Demo](https://jacob-nellis-code.github.io/refactored-pancake/)**

The web demo features:
- **Real-time animation**: Watch 3D objects rotate continuously in space
- **Interactive controls**: Start/stop animation and adjust rotation speed
- **Responsive design**: Works on desktop and mobile browsers

For local development of the web version, see the [web/README.md](web/README.md) for build instructions.

## CI/CD

This project uses GitHub Actions for continuous integration and deployment:

**Native Build (`.github/workflows/ci.yml`):**
- The code is automatically built
- All unit tests are executed
- The 3D renderer demo is run

**WebAssembly Build (`.github/workflows/deploy-web.yml`):**
- Compiles C++ to WebAssembly using Emscripten
- Deploys to GitHub Pages (main branch only)
- Live demo available at the link above
