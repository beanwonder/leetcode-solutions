cmake_minimum_required(VERSION 3.3)
project(leetcode_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 4sum.cc)
add_executable(leetcode_cpp ${SOURCE_FILES})