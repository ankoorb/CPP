cmake_minimum_required(VERSION 3.8)
project(12_Ensuring_Constant_Speed)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Screen.cpp Screen.h Swarm.cpp Swarm.h Particle.cpp Particle.h)
add_executable(12_Ensuring_Constant_Speed ${SOURCE_FILES})

find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(12_Ensuring_Constant_Speed ${SDL2_LIBRARY})