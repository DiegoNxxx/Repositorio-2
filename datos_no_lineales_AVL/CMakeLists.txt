cmake_minimum_required(VERSION 3.28)
project(AVL101)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVL101 main.cpp
        UserAVL.cpp
        UserAVL.h)
