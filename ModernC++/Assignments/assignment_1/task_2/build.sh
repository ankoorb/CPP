#!/usr/bin/env bash

echo "Task # 1: Build the ipb_arithmetic library"

rm -rf build
mkdir build

# Include headers directory using -I flag
c++ -I include/ -c src/subtract.cpp -o build/subtract.o
c++ -I include/ -c src/sum.cpp -o build/sum.o

# Archive the object files and create library
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

echo "Task # 2: Build the program"
# -I <headers directory>
# -L <library directory> -l<library name>
# -o <output file>
c++ src/main.cpp -I include/ -L build/ -lipb_arithmetic -o results/bin/example

echo "Build finished"
