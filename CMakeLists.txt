cmake_minimum_required(VERSION 3.14)
project(3DRenderer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directory
include_directories(include)

# Source files
set(SOURCES
    src/Vector3D.cpp
    src/Matrix4x4.cpp
    src/Object3D.cpp
    src/Renderer.cpp
)

# Create library
add_library(renderer_lib ${SOURCES})

# Main executable
add_executable(3d_renderer src/main.cpp)
target_link_libraries(3d_renderer renderer_lib)

# Enable testing
enable_testing()

# Google Test setup
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(
  renderer_tests
  tests/test_vector3d.cpp
  tests/test_matrix4x4.cpp
  tests/test_object3d.cpp
  tests/test_renderer.cpp
)

target_link_libraries(
  renderer_tests
  renderer_lib
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(renderer_tests)
