cmake_minimum_required(VERSION 3.8)
project(28_Getters_and_Setters)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.cpp Person.h)
add_executable(28_Getters_and_Setters ${SOURCE_FILES})