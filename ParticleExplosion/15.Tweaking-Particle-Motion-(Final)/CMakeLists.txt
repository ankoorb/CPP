cmake_minimum_required(VERSION 3.8)
project(15_Tweaking_Particle_Motion__Final_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Screen.cpp Screen.h Swarm.cpp Swarm.h Particle.cpp Particle.h)
add_executable(15_Tweaking_Particle_Motion__Final_ ${SOURCE_FILES})

find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(15_Tweaking_Particle_Motion__Final_ ${SDL2_LIBRARY})