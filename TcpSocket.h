#ifndef _TCP_SOCKET_
#define _TCP_SOCKET_
#include <string>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstdint>
#include <windows.h>

using std::string;
using std::cout;
using std::endl;

struct Error{
    string _msg;
    Error(const string msg) : _msg(msg) {}
    void Print(){cout << _msg << endl;}
};


class TcpSocket{
public:
    TcpSocket(const string ip, const int port);
    Error* Connection();
    Error* Recive(const int size, std::string& buffer);
    Error* Send(const string data);
    void Close();
private:
    string _ip;
    int _port;
    WSADATA _wsaData;
    SOCKET _socket;
    SOCKADDR_IN _socket_addr;
};

#endif
