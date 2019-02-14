cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME KeyLogger)
project(${PROJECT_NAME})

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
set(CMAKE_CXX_STANDARD 11) 

set(SOURCE main.cpp KeyLogger.cpp Key.cpp TcpSocket.cpp)

add_executable(KeyLogger ${SOURCE})
target_link_libraries(KeyLogger wsock32 ws2_32)
