cmake_minimum_required(VERSION 3.3)
project(CountSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES CountSort.cpp)
add_executable(CountSort ${SOURCE_FILES})