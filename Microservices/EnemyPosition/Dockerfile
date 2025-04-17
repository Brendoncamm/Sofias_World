FROM ubuntu:24.04

# Install dependencies
# Install dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    build-essential \
    python3 \
    python3-pip \
    git \
    wget \
    curl \
    libx11-dev \
    libxrandr-dev \
    libxcursor-dev \
    libxi-dev \
    libudev-dev \
    libgl1-mesa-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libfreetype6-dev

# Set the working directory
WORKDIR /app

# Copy all files into the container
COPY . .

COPY ../../common ./common
# Build the service using CMake

RUN rm -rf build && mkdir build && cd build && \
    cmake .. \
    && cmake --build .

# Expose the port the service listens on
EXPOSE 5000

# Command to run the servic
CMD ["./enemy_position_service"]