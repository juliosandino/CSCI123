cmake_minimum_required(VERSION 3.5)
project(H1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES H1.cpp)
add_executable(H1 ${SOURCE_FILES})