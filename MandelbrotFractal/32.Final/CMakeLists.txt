cmake_minimum_required(VERSION 3.8)
project(32_Final)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RGB.cpp RGB.h Mandelbrot.cpp Mandelbrot.h FractalCreator.cpp FractalCreator.h ZoomList.cpp ZoomList.h Zoom.h Bitmap.cpp Bitmap.h BitmapFileHeader.h BitmapInfoHeader.h)
add_executable(32_Final ${SOURCE_FILES})