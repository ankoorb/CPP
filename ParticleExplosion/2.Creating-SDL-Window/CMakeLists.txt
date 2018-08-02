cmake_minimum_required(VERSION 3.8)
project(2_Creating_SDL_Window)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(2_Creating_SDL_Window ${SOURCE_FILES})

find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(2_Creating_SDL_Window ${SDL2_LIBRARY})