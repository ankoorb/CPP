cmake_minimum_required(VERSION 3.8)
project(3_A_Bitmap_Class)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h)
add_executable(3_A_Bitmap_Class ${SOURCE_FILES})