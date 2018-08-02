cmake_minimum_required(VERSION 3.8)
project(4_Setting_Pixel_Colors)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(4_Setting_Pixel_Colors ${SOURCE_FILES})

find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(4_Setting_Pixel_Colors ${SDL2_LIBRARY})