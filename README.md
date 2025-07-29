# C++ Development Container

This project provides a development environment for C++ applications using a Docker container. It is configured to use the `libncurses-dev` package, which allows for advanced terminal handling.

## Project Structure

```
ncurses_test
├── .devcontainer
│   ├── devcontainer.json       # Configuration for the development container
│   └── Dockerfile              # Dockerfile to build the development environment
├── src
│   └── main.cpp                # Main entry point of the C++ application
├── Makefile                    # Build rules for the project
└── README.md                   # Project documentation
```

## Getting Started

To get started with this project, follow these steps:

1. **Clone the Repository**
   ```bash
   git clone <repository-url>
   ```

2. **Open in VS Code**
   Open the project in Visual Studio Code. If you have the Remote - Containers extension installed, you will be prompted to reopen the project in a container.

3. **Build the Container**
   Once the container is running, it will automatically install the necessary dependencies, including `libncurses-dev`.

4. **Build the Project**
   You can build the project using the provided Makefile:
   ```bash
   make
   ```

5. **Run the Application**
   After building, run the application:
   ```bash
   ./app
   ```

## Usage

This project is designed to demonstrate the use of the ncurses library for terminal-based applications. Modify `src/main.cpp` to implement your desired functionality.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.