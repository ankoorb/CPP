cmake_minimum_required(VERSION 3.8)
project(45_Namespaces)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dog.cpp Dog.h Animal.cpp Animal.h)
add_executable(45_Namespaces ${SOURCE_FILES})