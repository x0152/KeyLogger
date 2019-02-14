#ifndef HTTP_SENDER_H_
#define HTTP_SENDER_H_

#include <string>
#include <thread>
#include <iostream>
#include "TcpSocket.h"
#include "Windows.h"

static void WaitCommandStop(TcpSocket* _socket){
    Error* err = nullptr;
    while (err == nullptr){
        string buffer = "";
        err = _socket->Recive(sizeof("stop"), buffer);
        if (buffer == "stop"){
            _socket->Close();
            exit(-1);
        }
    }
}

class TcpSender{
public:
    TcpSender(std::string ip, int port){
        this->_socket = new TcpSocket(ip, port);

        Error* err = this->_socket->Connection();

        std::thread waitThreadCommandStop(WaitCommandStop, this->_socket);
        waitThreadCommandStop.detach();

        if (err != nullptr){
            err->Print();
        }
    }

    TcpSender& operator<< (const std::string key) {
        Error* err = this->_socket->Send(key);

        if (err != nullptr){
            err->Print();

            while(err != nullptr){
                Sleep(10000);
                err = this->_socket->Connection();
            }

            std::thread waitThreadCommandStop(WaitCommandStop, this->_socket);
            waitThreadCommandStop.detach();
        }


        return *this;
    }

    ~TcpSender(){
        this->_socket->Close();
    }
private:
    TcpSocket* _socket;
    std::string _ip;
    int _port;
};

#endif
