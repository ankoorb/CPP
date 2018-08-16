cmake_minimum_required(VERSION 3.8)
project(2_Bitmap_Info_Header)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapInfoHeader.h BitmapFileHeader.h)
add_executable(2_Bitmap_Info_Header ${SOURCE_FILES})