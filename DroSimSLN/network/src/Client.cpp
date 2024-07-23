#include "Client.h"
#include <iostream>
#include <string>
#include <cstring>

Client::Client(const std::string& name) {
    name_ = name;
    
    log(std::cout,"Initialising Winsock...");

    if (WSAStartup(MAKEWORD(2,2), &wsa_) != 0) {
        log(std::cerr,"Failed. Error code : " + std::to_string(WSAGetLastError()));
        return;
    }
    
    log(std::cout,"Initialised");

    if ((connectSocket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) {
        log(std::cerr,"Socket creation failed. Error code : " + std::to_string(WSAGetLastError()));
        WSACleanup();
        return;
    }
    
    clientService_.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &clientService_.sin_addr);
    clientService_.sin_port = htons(7777);

    const int iResult = connect(connectSocket_, (SOCKADDR*)&clientService_, sizeof(clientService_));
    if (iResult == SOCKET_ERROR) {
        log(std::cerr,"Failed to connect : " + std::to_string(WSAGetLastError()));
        closesocket(connectSocket_);
        WSACleanup();
        return;
    }
}

Client::~Client() {
    closesocket(connectSocket_);
    WSACleanup();
}

void Client::log(std::ostream& stream, const std::string& message) const {
    stream << name_ << " - " << message << '\n';
}

int Client::sendToServer(const std::string& message) const {
    const int iResult = send(connectSocket_, message.c_str(), message.length(), 0);
    if (iResult == SOCKET_ERROR) {
        log(std::cerr,"Failed to send message : " + std::to_string(WSAGetLastError()));
        closesocket(connectSocket_);
        WSACleanup();
        return 1;
    }
    log(std::cout,"Sent : " + message);
    return 0;
}

std::string Client::waitResponse() const {
    char recvbuf[512];
    const int iResult = recv(connectSocket_, recvbuf, 512, 0);
    if (iResult > 0) {
        const auto res = std::string(recvbuf, iResult);
        log(std::cout,"Got response : " + res);
        return res;
    }
    if (iResult == 0)
        log(std::cout,"Connection closed");
    else
        log(std::cerr,"Response error : " + std::to_string(WSAGetLastError()));
    return "";
}
