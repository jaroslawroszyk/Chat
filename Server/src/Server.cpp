#include <stdio.h>
// #include <winsock2.h>
#include <cstring>
// #include <exception>
#include <stdexcept>



int main()
{
    printf("I'm in\n");
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int clientAddrLen = sizeof(clientAddr);
    char buffer[1024];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        perror("WSAStartup failed");
        std::throw
            return 1;
    }

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
    {
        perror("Socket creation error");
        return 1;
    }

    // Bind socket to address and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345); // Port number

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
    {
        perror("Binding error");
        closesocket(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
    {
        perror("Listen error");
        closesocket(serverSocket);
        return 1;
    }

    printf("Server listening on port 12345...\n");

    // Accept and handle client connections
    while (1)
    {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == INVALID_SOCKET)
        {
            perror("Accept error");
            continue;
        }

        printf("Client connected\n");

        // Receive and send back data
        while (1)
        {
            memset(buffer, 0, sizeof(buffer));
            int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesRead == SOCKET_ERROR)
            {
                perror("Receive error");
                break;
            }
            if (bytesRead == 0)
            {
                printf("Client disconnected\n");
                break;
            }

            printf("Received from client: %s", buffer);
            send(clientSocket, buffer, bytesRead, 0);
        }

        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();

    getchar();

    return 0;
}
