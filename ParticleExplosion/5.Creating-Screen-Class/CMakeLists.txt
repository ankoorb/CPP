cmake_minimum_required(VERSION 3.8)
project(5_Creating_Screen_Class)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Screen.cpp Screen.h)
add_executable(5_Creating_Screen_Class ${SOURCE_FILES})

find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(5_Creating_Screen_Class ${SDL2_LIBRARY})