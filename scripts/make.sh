#!/bin/bash

# Define the project root and build directory
ROOT_DIR=$(realpath "$(dirname "$0")/..")
BUILD_DIR="$ROOT_DIR/build"
APP_DIR="$ROOT_DIR/app"

# Initialize flags
FRESH_BUILD=false
RUN_EXECUTABLE=false

# Function to display the help message
show_help() {
  cat << EOF
Usage: make.sh [options]

Options:
  -f, --fresh    Perform a fresh build by deleting the build and app directories first
  -h, --help     Display this help message
  -r, --run      Run the executable after building
EOF
  exit 0
}

# Parse flags
for arg in "$@"; do
  case $arg in
    -h|--help)
      show_help
      ;;
    -f|--fresh)
      FRESH_BUILD=true
      ;;
    -r|--run)
      RUN_EXECUTABLE=true
      ;;
    *)
      echo "Unknown option: $arg"
      show_help
      ;;
  esac
done

# Check if '--fresh' flag is passed and remove directories if it is
if [ "$FRESH_BUILD" = true ]; then
  echo "Performing a fresh build..."
  rm -rf "$BUILD_DIR" "$APP_DIR"
fi

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
  mkdir "$BUILD_DIR"
fi

# Create the app directory if it doesn't exist
if [ ! -d "$APP_DIR" ]; then
  mkdir "$APP_DIR"
fi

# Run CMake to configure the project and generate the Makefiles in the build directory
cmake -S "$ROOT_DIR/src" -B "$BUILD_DIR" -Wno-dev

# Build the project from the specified build directory
cmake --build "$BUILD_DIR"

# Copy the executable to the app directory
cp "$BUILD_DIR/datalink" "$APP_DIR"

# Notify the user
echo "Build complete. Executable is located in $APP_DIR."

# Check if '--run' flag is passed and run the executable if it is
if [ "$RUN_EXECUTABLE" = true ]; then
  echo "Running the executable..."
  "$APP_DIR/datalink"
fi