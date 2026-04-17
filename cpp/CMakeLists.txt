cmake_minimum_required(VERSION 3.20)
project(VaultCPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(Expression algo/stack/Expression.cpp)
add_executable(BinarySearch algo/binary-search/BinarySearch.cpp)

add_executable(MaxNumberOfKSumPair leetcode/1679/MaxNumberOfKSumPair.cpp)
add_executable(RotateArray leetcode/189/RotateArray.cpp)
add_executable(GuessNumberHigherOrLower leetcode/374/GuessNumberHigherOrLower.cpp)


find_package(GTest REQUIRED)
enable_testing()

function(add_gtest TARGET)
    add_executable(${TARGET} ${ARGN})
    target_link_libraries(${TARGET} PRIVATE GTest::GTest GTest::Main)
    add_test(NAME ${TARGET} COMMAND ${TARGET})
endfunction()

add_gtest(
        AlternatingSumTest
        leetcode/3701/AlternatingSumTest.cpp
        leetcode/3701/AlternatingSum.cpp
)

add_gtest(
        AlternateDigitSumTest
        leetcode/2544/AlternateDigitSumTest.cpp
        leetcode/2544/AlternateDigitSum.cpp
)

add_gtest(
    ValidAnagram
    leetcode/242/ValidAnagramTest.cpp
    leetcode/242/ValidAnagram.cpp
)
