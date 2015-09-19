cmake_minimum_required(VERSION 3.2)
project(CPP_Primer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp "Chapter 2/part1.cpp" "Chapter 2/part1.h" "Chapter 2/Sales_data.h" "Chapter 3/text.cpp" "Chapter 3/text.h" ch04.cpp ch04.h ch05.cpp ch05.h ch08.cpp ch08.h)
add_executable(CPP_Primer ${SOURCE_FILES} "Chapter 1/part1.h" "Chapter 1/part1.cpp")