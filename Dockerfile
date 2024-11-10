# Use an official Ubuntu base image
FROM ubuntu:20.04

# Set environment variables for non-interactive apt-get installs
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies for SDL2, OpenGL, and development tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libgl1-mesa-glx \
    libgl1-mesa-dev \
    libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-mixer-dev \
    libsdl2-ttf-dev \
    x11-utils \
    git \
    vim \
    && apt-get clean

# Set up the working directory
WORKDIR /workspace

# Expose display for OpenGL rendering
ENV DISPLAY=host.docker.internal:0

# Set the entrypoint (optional, you could customize this)
CMD ["bash"]
