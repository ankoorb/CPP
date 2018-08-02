cmake_minimum_required(VERSION 3.8)
project(1_Basic_SDL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(1_Basic_SDL ${SOURCE_FILES})

find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(1_Basic_SDL ${SDL2_LIBRARY})