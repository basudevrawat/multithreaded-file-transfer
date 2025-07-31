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
