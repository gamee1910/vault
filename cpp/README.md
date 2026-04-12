# C++ Module

This directory contains algorithm implementations and LeetCode problem solutions in C++.

## Directory Structure

### `/algo`
Contains basic algorithm implementations in C++:

- **`binary-search/`**
  - `BinarySearch.cpp` - Binary search algorithm implementation
  - Searches for an element in a sorted array with O(log n) time complexity

- **`stack/`**
  - `Expression.cpp` - Stack application for evaluating mathematical expressions
  - Supports conversion and evaluation of infix/postfix expressions

### `/leetcode`
Contains solutions to LeetCode problems:

- **`1679/`**
  - `MaxNumberOfKSumPair.cpp` - Solution to "Max Number of K-Sum Pairs" problem
  
- **`189/`**
  - `RotateArray.cpp` - Solution to "Rotate Array" problem

### Configuration Files

- **`CMakeLists.txt`** - CMake configuration file for building the project
- **`cmake-build-debug/`** - Build directory (auto-generated)

## Technologies

- **C++** - Programming language
- **CMake** - Build system
- **GCC/Clang** - C++ Compiler

## Requirements

- C++ Compiler (GCC or Clang)
- CMake 3.10+

## Build and Run

### Using CMake:

```bash
cd cpp
mkdir -p cmake-build-debug
cd cmake-build-debug
cmake ..
make
```

### Or using IDE (e.g., CLion):
CMake configuration will be automatically detected.

## Purpose

This directory is used for:
- Practicing basic algorithms in C++
- Solving LeetCode problems
- Learning about data structures
- Improving C++ programming skills

## Algorithms Covered

- **Binary Search** - Searching in sorted arrays
- **Stack Operations** - Stack applications for mathematical expressions
- **Array Manipulation** - Array-related problems
- **Pairing Problems** - Pairing and combination problems

