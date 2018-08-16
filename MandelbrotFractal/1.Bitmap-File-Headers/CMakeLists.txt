cmake_minimum_required(VERSION 3.8)
project(1_Bitmap_File_Headers)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitmapFileHeader.h)
add_executable(1_Bitmap_File_Headers ${SOURCE_FILES})