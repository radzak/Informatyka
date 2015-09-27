cmake_minimum_required(VERSION 3.3)
project(QuickSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES QuickSort.cpp)
add_executable(QuickSort ${SOURCE_FILES})