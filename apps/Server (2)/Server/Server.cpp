#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

std::vector<std::string> fortunes = {
    "Hello",
    "World0",
    "!"
};

int main() {
    // create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // bind socket to port 9876
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(9876);
    if (bind(server_socket, (sockaddr*)&server_address, sizeof(server_address)) == -1) {
        std::cerr << "Error binding socket to port 9876" << std::endl;
        return 1;
    }

    // listen for incoming connections
    if (listen(server_socket, SOMAXCONN) == -1) {
        std::cerr << "Error listening on socket" << std::endl;
        return 1;
    }

    std::cout << "Server started listening on port 9876" << std::endl;

    while (true) {
        // accept incoming connection
        sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_socket = accept(server_socket, (sockaddr*)&client_address, &client_address_size);
        if (client_socket == -1) {
            std::cerr << "Error accepting incoming connection" << std::endl;
            continue;
        }

        std::cout << "Accepted incoming connection from " << inet_ntoa(client_address.sin_addr) << std::endl;

        // select random fortune from list
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, fortunes.size() - 1);
        std::string fortune = fortunes[dis(gen)];

        // send fortune to client
        if (send(client_socket, fortune.c_str(), fortune.length(), 0) == -1) {
            std::cerr << "Error sending fortune to client" << std::endl;
            close(client_socket);
            continue;
        }

        std::cout << "Sent fortune to client: " << fortune << std::endl;

        // close client connection
        close(client_socket);
    }

    // close server socket
    close(server_socket);

    return 0;
}
