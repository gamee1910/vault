cmake_minimum_required(VERSION 4.2)
project(vault)

set(CMAKE_CXX_STANDARD 14)

include_directories(cpp/stack)

add_executable(vault
        cpp/stack/Expression.cpp
        cpp/stack/Expression.h)
