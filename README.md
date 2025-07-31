Multithreaded File Transfer System: This is a multithreaded client-server file transfer system implemented in C++. It allows a client to request files from a server over TCP. The server handles multiple clients simultaneously using POSIX threads.

Features include :
Multithreaded server using `pthread` to handle multiple clients concurrently
Secure file transfer over TCP sockets
Simple command-line interface
Cross-platform C++ code (Linux/macOS)

Working:
The **server** listens for incoming connections on a specified port.
The **client** connects to the server and requests a file by name.
The server checks for the file and sends its contents if it exists.
The client saves the file locally with a `received_` prefix.

To Compile:
Have `g++` installed.

Compile Server:
```bash
g++ server.cpp -o server -lpthread
