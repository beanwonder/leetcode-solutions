cmake_minimum_required(VERSION 3.3)
project(leetcode_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES n_queens_II.cc)
add_executable(leetcode_cpp ${SOURCE_FILES})