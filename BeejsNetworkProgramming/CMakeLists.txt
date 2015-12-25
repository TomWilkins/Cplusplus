cmake_minimum_required(VERSION 3.3)
project(BeejsNetworkProgramming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        showIP.cpp
        StreamSocketServerDemo.cpp StreamSocketClientDemo.cpp DatagramSocketServerDemo.cpp DatagramSocketClientDemo.cpp.cpp)

add_executable(BeejsNetworkProgramming ${SOURCE_FILES})