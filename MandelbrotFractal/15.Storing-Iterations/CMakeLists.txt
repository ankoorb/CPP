cmake_minimum_required(VERSION 3.8)
project(15_Storing_Iterations)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h)
add_executable(15_Storing_Iterations ${SOURCE_FILES})