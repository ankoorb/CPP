cmake_minimum_required(VERSION 3.8)
project(53_Creating_Static_Libraries)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dog.cpp Dog.h)
add_library(53_Creating_Static_Libraries ${SOURCE_FILES})