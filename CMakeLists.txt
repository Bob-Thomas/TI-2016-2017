cmake_minimum_required(VERSION 3.5)
project(TI_2016_2017)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp)
add_executable(TI_2016_2017 ${SOURCE_FILES})