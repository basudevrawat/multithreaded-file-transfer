#include <iostream>
#include <fstream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5001
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

    if (connect(sock, (sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed\n";
        return -1;
    }

    std::string filename;
    std::cout << "Enter filename to request: ";
    std::cin >> filename;
    send(sock, filename.c_str(), filename.size(), 0);

    int bytes = recv(sock, buffer, BUFFER_SIZE, 0);
    std::string response(buffer, bytes);

    if (response != "OK") {
        std::cerr << "[!] Server response: " << response << "\n";
        close(sock);
        return 1;
    }

    std::ofstream outfile("received_" + filename, std::ios::binary);
    while ((bytes = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        outfile.write(buffer, bytes);
    }

    std::cout << "[+] File received as 'received_" << filename << "'\n";
    outfile.close();
    close(sock);
    return 0;
}