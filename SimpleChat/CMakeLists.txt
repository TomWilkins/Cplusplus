cmake_minimum_required(VERSION 3.3)
project(SimpleChat)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Client.cpp
        Server.cpp)

add_executable(SimpleChat ${SOURCE_FILES})