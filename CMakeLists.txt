cmake_minimum_required(VERSION 3.5)
project(TI_2016_2017)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
include_directories(Catch/include)
include_directories(bmptk)
include_directories(hwlib)

set(SOURCE_FILES Catch/include/catch_with_main.hpp template_string/main.cpp template_string/template_string.h template_string/catch_include.h)
add_executable(template_string ${SOURCE_FILES})