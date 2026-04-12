cmake_minimum_required(VERSION 3.20)
project(VaultCPP)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Expression algo/stack/Expression.cpp algo/stack/Expression.h)
add_executable(MaxNumberOfKSumPair leetcode/1679/MaxNumberOfKSumPair.cpp)
add_executable(RotateArray leetcode/189/RotateArray.cpp)