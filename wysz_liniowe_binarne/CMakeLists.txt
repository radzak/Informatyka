cmake_minimum_required(VERSION 3.3)
project(wysz_liniowe_binarne)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES wysz_liniowe_binarne.cpp)
add_executable(wysz_liniowe_binarne ${SOURCE_FILES})