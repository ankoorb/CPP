cmake_minimum_required(VERSION 3.8)
project(3_Textures_Renderers_Buffers)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(3_Textures_Renderers_Buffers ${SOURCE_FILES})

find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(3_Textures_Renderers_Buffers ${SDL2_LIBRARY})