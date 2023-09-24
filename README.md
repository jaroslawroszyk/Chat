<div align="left">
  <img title="title" src="./assets/icon.svg" alt="icon" align="left" width="100" style="padding-right: 1ch">
  <h1>ChatApp</h1>
  <p><strong>The Chat is an application that enables communication between clients through a server. Clients can send and receive messages and participate in chats.</strong></p>
</div>

[![Project Status](https://www.repostatus.org/badges/latest/active.svg)](https://www.repostatus.org/#active)
[![License MIT](https://img.shields.io/badge/license-MIT-blue)](#license)

## Getting Started

This project uses submodules to clone the repo correctly you should:
```
git clone --recursive [url to repo]
```

If you have already cloned the project, you should update the submodules:
```
git submodule update --init --recursive
```

## Project Structure

The project consists of two main components: `Server` and `Client`.

### Building the application:

To build the application, follow these steps:

1. Create folder `build` in main directory
   ```
   mkdir -p build && cd build
   ```
2. Choose your preferred generator, for example:
   - For UNIX systems using Make:
     ```
     cmake ..
     make
     ```
   - For UNIX systems using Ninja:
     ```
     cmake -G Ninja ..
     ninja
     ```

## Running the Application

After building both the server and client, you can run the chat application.

## Running the Client:

Navigate to the `build/Client/` directory and run the Client:
```
./Client
```
## Running Server

Navigate to the `build/Server/` directory and run the Server:
```
./Server
```

## Requirements

To build and run the project, you'll need:

- A C++20-compatible compiler
- CMake (version 3.17 or newer)
- Google Test library (automatically fetched by CMake)

## Authors

- TODO:

## License

This project is licensed under the [MIT] - see the [LICENSE](LICENSE/LICENSE) file for details.