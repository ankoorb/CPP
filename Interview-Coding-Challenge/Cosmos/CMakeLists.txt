cmake_minimum_required(VERSION 3.10)

project(Cosmos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cosmos main.cpp Universe.cpp Universe.h Object.cpp Object.h Star.cpp Star.h Planet.cpp Planet.h Galaxy.cpp Galaxy.h)