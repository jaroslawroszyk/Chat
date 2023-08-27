# Chat

The Chat is an application that enables communication between clients through a server. Clients can send and receive messages and participate in chats.

## Project Structure

The project consists of two main components: `Server` and `Client`.

### Server

The `Server` folder contains the server implementation and its associated unit tests.

#### Directory Structure:

- `include`: Contains header files for server-related classes.
- `src`: Contains source files implementing the server's logic.
- `tests`: Contains unit tests for the server.

#### Building the Server:

To build the server, follow these steps:

1. Navigate to the `Server` folder:
   ```
   cd Server
   ```
2. Create the `build` directory (if not already present) and navigate into it:
   ```
   mkdir -p build && cd build
   ```
3. Choose your preferred generator, for example:
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

### Client

The `Client` folder contains the client implementation and its associated unit tests.

#### Directory Structure:

- `include`: Contains header files for client-related classes.
- `src`: Contains source files implementing the client's logic.
- `tests`: Contains unit tests for the client.

#### Building the Client:

To build the client, follow these steps:

1. Navigate to the `Client` folder:
   ```
   cd Client
   ```
2. Create the `build` directory (if not already present) and navigate into it:
   ```
   mkdir -p build && cd build
   ```
3. Choose your preferred generator, for example:
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

### Running the Application

After building both the server and client, you can run the chat application.

#### Running the Server:

Navigate to the `Server/build` directory and run the server:
```
./chat_server
```

#### Running the Client:

Navigate to the `Client/build` directory and run the client:
```
./chat_client
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