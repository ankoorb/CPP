cmake_minimum_required(VERSION 3.8)
project(5_Bitmap_Header_Values)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Bitmap.cpp Bitmap.h BitmapFileHeader.h BitmapInfoHeader.h)
add_executable(5_Bitmap_Header_Values ${SOURCE_FILES})