cmake_minimum_required(VERSION 3.14)
project(3DRendererWeb)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add parent directory includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Collect source files from parent src directory (excluding main.cpp)
set(SOURCES
    ../src/Vector3D.cpp
    ../src/Matrix4x4.cpp
    ../src/Object3D.cpp
    ../src/Renderer.cpp
    main_web.cpp
)

# Create the executable
add_executable(renderer ${SOURCES})

# Emscripten-specific settings
if(EMSCRIPTEN)
    set_target_properties(renderer PROPERTIES
        LINK_FLAGS "\
            -s WASM=1 \
            -s ALLOW_MEMORY_GROWTH=1 \
            -s NO_EXIT_RUNTIME=0 \
            -s EXPORTED_RUNTIME_METHODS=['ccall','cwrap'] \
            -s EXPORTED_FUNCTIONS=['_main'] \
            -s MODULARIZE=0 \
            -s INVOKE_RUN=1 \
            -s INITIAL_MEMORY=16777216"
    )

    # Set output directory
    set_target_properties(renderer PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # Additional compiler flags
    target_compile_options(renderer PRIVATE
        -O3
    )
endif()
