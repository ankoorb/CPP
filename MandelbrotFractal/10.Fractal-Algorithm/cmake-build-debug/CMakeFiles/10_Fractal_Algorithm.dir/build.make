# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/10_Fractal_Algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/10_Fractal_Algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/10_Fractal_Algorithm.dir/flags.make

CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o: CMakeFiles/10_Fractal_Algorithm.dir/flags.make
CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o -c "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/main.cpp"

CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/main.cpp" > CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.i

CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/main.cpp" -o CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.s

CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o.requires

CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o.provides: CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/10_Fractal_Algorithm.dir/build.make CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o.provides

CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o.provides.build: CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o


CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o: CMakeFiles/10_Fractal_Algorithm.dir/flags.make
CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o: ../Bitmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o -c "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/Bitmap.cpp"

CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/Bitmap.cpp" > CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.i

CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/Bitmap.cpp" -o CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.s

CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o.requires:

.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o.requires

CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o.provides: CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o.requires
	$(MAKE) -f CMakeFiles/10_Fractal_Algorithm.dir/build.make CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o.provides.build
.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o.provides

CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o.provides.build: CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o


CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o: CMakeFiles/10_Fractal_Algorithm.dir/flags.make
CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o: ../Mandelbrot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o -c "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/Mandelbrot.cpp"

CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/Mandelbrot.cpp" > CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.i

CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/Mandelbrot.cpp" -o CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.s

CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o.requires:

.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o.requires

CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o.provides: CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o.requires
	$(MAKE) -f CMakeFiles/10_Fractal_Algorithm.dir/build.make CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o.provides.build
.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o.provides

CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o.provides.build: CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o


# Object files for target 10_Fractal_Algorithm
10_Fractal_Algorithm_OBJECTS = \
"CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o" \
"CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o" \
"CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o"

# External object files for target 10_Fractal_Algorithm
10_Fractal_Algorithm_EXTERNAL_OBJECTS =

10_Fractal_Algorithm: CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o
10_Fractal_Algorithm: CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o
10_Fractal_Algorithm: CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o
10_Fractal_Algorithm: CMakeFiles/10_Fractal_Algorithm.dir/build.make
10_Fractal_Algorithm: CMakeFiles/10_Fractal_Algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable 10_Fractal_Algorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/10_Fractal_Algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/10_Fractal_Algorithm.dir/build: 10_Fractal_Algorithm

.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/build

CMakeFiles/10_Fractal_Algorithm.dir/requires: CMakeFiles/10_Fractal_Algorithm.dir/main.cpp.o.requires
CMakeFiles/10_Fractal_Algorithm.dir/requires: CMakeFiles/10_Fractal_Algorithm.dir/Bitmap.cpp.o.requires
CMakeFiles/10_Fractal_Algorithm.dir/requires: CMakeFiles/10_Fractal_Algorithm.dir/Mandelbrot.cpp.o.requires

.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/requires

CMakeFiles/10_Fractal_Algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/10_Fractal_Algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/clean

CMakeFiles/10_Fractal_Algorithm.dir/depend:
	cd "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm" "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm" "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug" "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug" "/Users/ankoor/Desktop/Programming/Advanced C++/MandelbrotFractal/10.Fractal-Algorithm/cmake-build-debug/CMakeFiles/10_Fractal_Algorithm.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/10_Fractal_Algorithm.dir/depend
