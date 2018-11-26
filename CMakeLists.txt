cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME KeyLogger)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11) 

#set(HEADER Key.h KeyLogger.h)
set(SOURCE main.cpp KeyLogger.cpp Key.cpp)

add_executable(KeyLogger ${SOURCE})
