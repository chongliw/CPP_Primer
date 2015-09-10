cmake_minimum_required(VERSION 3.2)
project(CPP_Primer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(CPP_Primer ${SOURCE_FILES} "Chapter 1/part1.h" "Chapter 1/part1.cpp")