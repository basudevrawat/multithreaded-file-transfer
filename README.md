# Multithreaded File Transfer System (C++)

A simple multithreaded TCP file transfer system using C++. The server supports multiple concurrent client connections using `std::thread`.

## Features
- Multithreaded file server using POSIX sockets
- File transfer over TCP
- Thread-per-client architecture

## Usage

### 1. Compile

```bash
g++ -std=c++17 server.cpp -o server
g++ -std=c++17 client.cpp -o client


![Image](https://github.com/user-attachments/assets/286d4ec1-1a5c-4954-814b-8712e2fd7998)
![Image](https://github.com/user-attachments/assets/e97ce2ca-d9bc-45c4-9bda-75fde95ca766)