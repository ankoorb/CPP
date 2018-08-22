cmake_minimum_required(VERSION 3.8)
project(8_Scaling)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h)
add_executable(8_Scaling ${SOURCE_FILES})