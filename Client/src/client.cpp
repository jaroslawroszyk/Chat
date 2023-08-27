#include <iostream>
#include "Client.hpp"

Client::Client() : id(0) {}

Client::Client(int id) : id(id) {}

auto Client::print() -> void
{
    std::cout << "Hello I'm a Client";
}

auto Client::getId() -> int
{
    return id;
}
/*
printf("I'm in\n");
WSADATA wsaData;
SOCKET clientSocket;
struct sockaddr_in serverAddr;
char buffer[1024];

// Initialize Winsock
if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    perror("WSAStartup failed");
    return 1;
}

// Create socket
clientSocket = socket(AF_INET, SOCK_STREAM, 0);
if (clientSocket == INVALID_SOCKET) {
    perror("Socket creation error");
    WSACleanup();
    return 1;
}

// Configure server address and port
serverAddr.sin_family = AF_INET;
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address
serverAddr.sin_port = htons(12345); // Server port

// Connect to the server
if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
    perror("Connection error");
    closesocket(clientSocket);
    WSACleanup();
    return 1;
}

printf("Connected to server\n");

// Send and receive data
while (1) {
    printf("Enter a message: ");
    fgets(buffer, sizeof(buffer), stdin);

    send(clientSocket, buffer, strlen(buffer), 0);

    if (strcmp(buffer, "exit\n") == 0) {
        printf("Exiting...\n");
        break;
    }

    memset(buffer, 0, sizeof(buffer));
    int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == SOCKET_ERROR) {
        perror("Receive error");
        break;
    }
    if (bytesRead == 0) {
        printf("Server disconnected\n");
        break;
    }

    printf("Server response: %s\n", buffer);
}

closesocket(clientSocket);
WSACleanup();

getchar();

return 0;
*/
