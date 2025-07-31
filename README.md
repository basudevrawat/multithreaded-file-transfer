Multithreaded File Transfer System: This is a multithreaded client-server file transfer system implemented in C++. It allows a client to request files from a server over TCP. The server handles multiple clients simultaneously using POSIX threads.

Features include: Multithreaded server using `pthread` to handle multiple clients concurrently, Secure file transfer over TCP sockets, Simple command-line interface, Cross-platform C++ code (Linux/macOS)

Working: 
First Step: The **server** listens for incoming connections on a specified port. 
Second Step: The **client** connects to the server and requests a file by name.
Third Step: The server checks for the file and sends its contents if it exists.
Fourth Step: The client saves the file locally with a `received_` prefix.

To Compile: We need `g++` installed.

Compile Server: ```bash
g++ server.cpp -o server -lpthread
