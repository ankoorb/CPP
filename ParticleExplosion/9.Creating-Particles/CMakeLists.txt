cmake_minimum_required(VERSION 3.8)
project(9_Creating_Particles)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Screen.cpp Screen.h Particle.cpp Particle.h Swarm.cpp Swarm.h)
add_executable(9_Creating_Particles ${SOURCE_FILES})


find_package(SDL2)
set(SDL2_LIBRARY /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib)
target_link_libraries(9_Creating_Particles ${SDL2_LIBRARY})