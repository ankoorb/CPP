cmake_minimum_required(VERSION 3.8)
project(4_Bitmap_Memory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h)
add_executable(4_Bitmap_Memory ${SOURCE_FILES})