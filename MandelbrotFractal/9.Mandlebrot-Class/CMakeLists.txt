cmake_minimum_required(VERSION 3.8)
project(9_Mandlebrot_Class)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h)
add_executable(9_Mandlebrot_Class ${SOURCE_FILES})