cmake_minimum_required(VERSION 3.8)
project(7_Setting_Bitmap_Pixels)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Bitmap.cpp Bitmap.h BitmapFileHeader.h BitmapInfoHeader.h)
add_executable(7_Setting_Bitmap_Pixels ${SOURCE_FILES})