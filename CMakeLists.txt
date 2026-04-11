cmake_minimum_required(VERSION 4.2)
project(vault)

set(CMAKE_CXX_STANDARD 14)

include_directories(cpp/algo/stack)

add_executable(vault
        cpp/algo/stack/Expression.cpp
        cpp/algo/stack/Expression.h)
