cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME KeyLogger)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17) 

#set(HEADER Key.h KeyLogger.h)
<<<<<<< Updated upstream
set(SOURCE main.cpp KeyLogger.cpp Key.cpp)
=======
set(SOURCE main.cpp KeyLogger.cpp Key.cpp TcpSocket.cpp)
>>>>>>> Stashed changes

add_executable(KeyLogger ${SOURCE})
