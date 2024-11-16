cmake_minimum_required(VERSION 3.28)
project(LoadBalancer101)

set(CMAKE_CXX_STANDARD 17)

add_executable(LoadBalancer101 main.cpp
        LoadBalancer.cpp
        LoadBalancer.h)
