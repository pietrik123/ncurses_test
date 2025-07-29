# Use a suitable base image for C++ development on Linux
# Ubuntu is a common and well-supported choice
FROM ubuntu:22.04

# Set environment variables (optional but good practice)
ENV DEBIAN_FRONTEND=noninteractive

# Update apt and install necessary packages
# build-essential: For g++ and other build tools
# libncurses-dev: Development files for ncurses
# git: Useful for cloning repositories within the container
# cmake, make: Common build systems for C++ projects
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    libncurses-dev \
    git \
    cmake \
    make \
    valgrind \
    gdb \
    && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /workspaces/ncurses_test

# (Optional) Copy your source code into the container.
# For devcontainers, VS Code will often mount your local workspace,
# so this might not be strictly necessary here, but it's good for a standalone Docker image.
COPY . .

# (Optional) Define a default command if running the container directly
# For devcontainers, this is usually overridden by VS Code's entrypoint
CMD ["bash"]