cmake_minimum_required(VERSION 3.8)
project(16_Using_Histogram)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapInfoHeader.h BitmapFileHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h)
add_executable(16_Using_Histogram ${SOURCE_FILES})