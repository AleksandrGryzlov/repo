#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 9876
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <server_ip>" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Error creating socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid server IP address" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error connecting to server" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Send request to server
    if (write(client_socket, "Fortune please!", strlen("Fortune please!")) < 0) {
        std::cerr << "Error sending request to server" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (read(client_socket, buffer, BUFFER_SIZE) < 0) {
        std::cerr << "Error receiving response from server" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Fortune: " << buffer << std::endl;

    // Close socket
    close(client_socket);

    return 0;
}
