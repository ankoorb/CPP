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
CMAKE_SOURCE_DIR = "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/43_5_Allocating_Memory_Exercise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/43_5_Allocating_Memory_Exercise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/43_5_Allocating_Memory_Exercise.dir/flags.make

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o: CMakeFiles/43_5_Allocating_Memory_Exercise.dir/flags.make
CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o -c "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/main.cpp"

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/main.cpp" > CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.i

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/main.cpp" -o CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.s

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o.requires

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o.provides: CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/43_5_Allocating_Memory_Exercise.dir/build.make CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o.provides

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o.provides.build: CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o


# Object files for target 43_5_Allocating_Memory_Exercise
43_5_Allocating_Memory_Exercise_OBJECTS = \
"CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o"

# External object files for target 43_5_Allocating_Memory_Exercise
43_5_Allocating_Memory_Exercise_EXTERNAL_OBJECTS =

43_5_Allocating_Memory_Exercise: CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o
43_5_Allocating_Memory_Exercise: CMakeFiles/43_5_Allocating_Memory_Exercise.dir/build.make
43_5_Allocating_Memory_Exercise: CMakeFiles/43_5_Allocating_Memory_Exercise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 43_5_Allocating_Memory_Exercise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/43_5_Allocating_Memory_Exercise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/43_5_Allocating_Memory_Exercise.dir/build: 43_5_Allocating_Memory_Exercise

.PHONY : CMakeFiles/43_5_Allocating_Memory_Exercise.dir/build

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/requires: CMakeFiles/43_5_Allocating_Memory_Exercise.dir/main.cpp.o.requires

.PHONY : CMakeFiles/43_5_Allocating_Memory_Exercise.dir/requires

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/43_5_Allocating_Memory_Exercise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/43_5_Allocating_Memory_Exercise.dir/clean

CMakeFiles/43_5_Allocating_Memory_Exercise.dir/depend:
	cd "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise" "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise" "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/cmake-build-debug" "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/cmake-build-debug" "/Users/ankoor/Desktop/Programming/C++/43.5.Allocating Memory Exercise/cmake-build-debug/CMakeFiles/43_5_Allocating_Memory_Exercise.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/43_5_Allocating_Memory_Exercise.dir/depend
