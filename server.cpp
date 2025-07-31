#include <iostream>
#include <fstream>
#include <thread>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 5001
#define BUFFER_SIZE 1024

void handle_client(int client_socket, sockaddr_in client_addr) {
    char buffer[BUFFER_SIZE] = {0};

    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        std::cerr << "[!] Failed to receive filename.\n";
        close(client_socket);
        return;
    }

    std::string filename(buffer);
    std::cout << "[+] Client requested file: " << filename << "\n";

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::string err_msg = "ERROR: File not found";
        send(client_socket, err_msg.c_str(), err_msg.size(), 0);
        close(client_socket);
        return;
    }

    send(client_socket, "OK", 2, 0);
    usleep(50000);

    while (!file.eof()) {
        file.read(buffer, BUFFER_SIZE);
        int bytes_read = file.gcount();
        send(client_socket, buffer, bytes_read, 0);
    }

    std::cout << "[+] Sent file: " << filename << "\n";
    file.close();
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (sockaddr *)&address, sizeof(address));
    listen(server_fd, 5);
    std::cout << "[*] Server listening on port " << PORT << "\n";

    while (true) {
        client_socket = accept(server_fd, (sockaddr *)&address, &addrlen);
        std::thread t(handle_client, client_socket, address);
        t.detach();
    }

    return 0;
}