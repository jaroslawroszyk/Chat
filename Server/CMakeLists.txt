cmake_minimum_required(VERSION 3.8)
project(Client)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
enable_testing()


add_subdirectory(googletest)

add_library(Client STATIC include/Server.hpp src/Server.cpp
        include/UserModel.hpp
        src/UserModel.cpp
        src/UserModel.cpp
        src/ChatModel.cpp
        include/ChatModel.h
        src/MessageModel.cpp
        include/MessageModel.hpp
        src/connector.cpp
        include/connector.h
)

add_subdirectory(tests)
