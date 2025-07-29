FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    libncurses-dev \
    gdb \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /workspace

# Copy the project files into the container
COPY . /workspace

# Set the default command to run when starting the container
CMD ["bash"]