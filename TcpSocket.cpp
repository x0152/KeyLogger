#include "TcpSocket.h"

TcpSocket::TcpSocket(const string ip, const int port) : _ip(ip), _port(port){ 
    WSAStartup(MAKEWORD(2,2), &this->_wsaData);
}

Error* TcpSocket::Connection(){
    this->_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(this->_socket == INVALID_SOCKET) {
        return new Error("Failed created socket %ld\n" +  std::to_string(WSAGetLastError()) + "\r\n");
        WSACleanup();
    }

    this->_socket_addr.sin_family = AF_INET;
    this->_socket_addr.sin_port = htons(this->_port);
    this->_socket_addr.sin_addr.s_addr = inet_addr(this->_ip.c_str());

    int returnCode = connect(this->_socket, (SOCKADDR *) &this->_socket_addr, sizeof(this->_socket_addr));


    if(returnCode != 0){
        return new Error("Client: connect() failed! Error code: " + std::to_string(WSAGetLastError()) + "\r\n");
        closesocket(this->_socket);
    }

    return nullptr;
}

Error* TcpSocket::Send(const string data){
    int n = send(this->_socket, data.c_str(), data.length(), 0);

    if(n == SOCKET_ERROR){
        return new Error("Client: send () failed! Error code: " + std::to_string(WSAGetLastError()) + "\r\n");
    }

    return nullptr;
}

Error* TcpSocket::Recive(const int size, std::string& buffer){
    char *buf = new char[size];
    int n = recv(this->_socket, buf, size, 0);

    if(n == SOCKET_ERROR){
        return new Error("Client: send () failed! Error code: " + std::to_string(WSAGetLastError()) + "\r\n");
    }

    buffer = buf;

    delete buf;

    return nullptr;
}

void TcpSocket::Close(){
    shutdown(this->_socket, SD_SEND);
    WSACleanup();
}

