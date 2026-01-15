# Web Version - 3D Object Renderer

This directory contains the WebAssembly version of the 3D Object Renderer, allowing it to run directly in web browsers.

## Live Demo

Once deployed, the live demo will be available at: `https://<username>.github.io/<repository-name>/`

## Building Locally

### Prerequisites

- [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html)

### Build Instructions

1. Install Emscripten:
```bash
# Get the emsdk repo
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk

# Download and install the latest SDK tools
./emsdk install latest

# Activate the SDK
./emsdk activate latest

# Set up the environment variables
source ./emsdk_env.sh
```

2. Build the WebAssembly version:
```bash
cd web
mkdir -p build
cd build
emcmake cmake ..
emmake make
```

3. Serve locally:
```bash
# From the web directory
python3 -m http.server 8000
```

4. Open your browser to `http://localhost:8000`

## How It Works

The C++ code is compiled to WebAssembly using Emscripten, which creates:
- `renderer.wasm`: The compiled WebAssembly binary
- `renderer.js`: JavaScript glue code to load and run the WASM module
- `index.html`: The web interface (custom HTML, not generated)

The HTML page captures the C++ `std::cout` output and displays it in a styled `<div>` element, preserving the ASCII art rendering.

## Deployment

The project uses GitHub Actions to automatically:
1. Build the WebAssembly version when changes are pushed
2. Deploy to GitHub Pages for the main branch

See `.github/workflows/deploy-web.yml` for the CI/CD configuration.

## Files

- `index.html`: Main web interface with styling and JavaScript
- `main_web.cpp`: Web-specific entry point (identical to main `main.cpp`)
- `CMakeLists.txt`: Emscripten-specific build configuration
- `build/`: Build output directory (gitignored)
