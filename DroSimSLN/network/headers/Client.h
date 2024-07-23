#pragma once

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <cstring>

#pragma comment(lib,"ws2_32.lib")

class Client {
    std::string name_;
    WSADATA wsa_;
    SOCKET connectSocket_;
    sockaddr_in clientService_;
public:
    Client(const std::string& name);
    ~Client();
    void log(std::ostream& stream, const std::string& message) const;
    int sendToServer(const std::string& message) const;
    std::string waitResponse() const;
};
