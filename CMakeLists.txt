# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(Project_E)

# Set the C++ standard to C++17 (or change to another version if necessary)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use pkg-config to find SDL2
find_package(PkgConfig REQUIRED)

# Find SDL2 with pkg-config
pkg_check_modules(SDL2 REQUIRED sdl2)

# Include SDL2 headers from pkg-config
include_directories(${SDL2_INCLUDE_DIRS})

# Link SDL2 libraries from pkg-config
set(LINK_LIBRARIES ${SDL2_LIBRARIES})

# Find OpenGL (this should work on most systems)
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

# Add the glad source directory (where glad.c is located)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add your source files, including glad.c
set(SOURCES
    src/main.cpp
    src/glad.c   # Add glad.c here to compile it
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the necessary libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${LINK_LIBRARIES}  # Link SDL2 using pkg-config
    OpenGL::GL         # Link OpenGL
    dl                  # Link libdl for dynamic loading functions
)
