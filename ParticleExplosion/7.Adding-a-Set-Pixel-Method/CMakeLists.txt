cmake_minimum_required(VERSION 3.8)
project(7_Adding_a_Set_Pixel_Method)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Screen.cpp Screen.h)
add_executable(7_Adding_a_Set_Pixel_Method ${SOURCE_FILES})


find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(7_Adding_a_Set_Pixel_Method ${SDL2_LIBRARY})