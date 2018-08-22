cmake_minimum_required(VERSION 3.8)
project(18_Zoom_Class)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapFileHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h BitmapInfoHeader.h Zoom.h)
add_executable(18_Zoom_Class ${SOURCE_FILES})