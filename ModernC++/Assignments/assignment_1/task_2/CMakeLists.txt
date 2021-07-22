cmake_minimum_required(VERSION 3.1)
project(task_2)
set(CMAKE_CXX_STANDARD 17)

# Header files
include_directories(include/)

# Add library
add_library(ipb_arithmetic src/sum.cpp src/subtract.cpp)

# Add executable main
add_executable(example_output src/main.cpp)

# Link/Bind objects together
target_link_libraries(example_output ipb_arithmetic)