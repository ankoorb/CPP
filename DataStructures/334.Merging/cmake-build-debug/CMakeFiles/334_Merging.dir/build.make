# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /Users/ankoor/Desktop/Programming/DS/334.Merging

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ankoor/Desktop/Programming/DS/334.Merging/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/334_Merging.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/334_Merging.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/334_Merging.dir/flags.make

CMakeFiles/334_Merging.dir/main.cpp.o: CMakeFiles/334_Merging.dir/flags.make
CMakeFiles/334_Merging.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ankoor/Desktop/Programming/DS/334.Merging/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/334_Merging.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/334_Merging.dir/main.cpp.o -c /Users/ankoor/Desktop/Programming/DS/334.Merging/main.cpp

CMakeFiles/334_Merging.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/334_Merging.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ankoor/Desktop/Programming/DS/334.Merging/main.cpp > CMakeFiles/334_Merging.dir/main.cpp.i

CMakeFiles/334_Merging.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/334_Merging.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ankoor/Desktop/Programming/DS/334.Merging/main.cpp -o CMakeFiles/334_Merging.dir/main.cpp.s

CMakeFiles/334_Merging.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/334_Merging.dir/main.cpp.o.requires

CMakeFiles/334_Merging.dir/main.cpp.o.provides: CMakeFiles/334_Merging.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/334_Merging.dir/build.make CMakeFiles/334_Merging.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/334_Merging.dir/main.cpp.o.provides

CMakeFiles/334_Merging.dir/main.cpp.o.provides.build: CMakeFiles/334_Merging.dir/main.cpp.o


# Object files for target 334_Merging
334_Merging_OBJECTS = \
"CMakeFiles/334_Merging.dir/main.cpp.o"

# External object files for target 334_Merging
334_Merging_EXTERNAL_OBJECTS =

334_Merging: CMakeFiles/334_Merging.dir/main.cpp.o
334_Merging: CMakeFiles/334_Merging.dir/build.make
334_Merging: CMakeFiles/334_Merging.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ankoor/Desktop/Programming/DS/334.Merging/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 334_Merging"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/334_Merging.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/334_Merging.dir/build: 334_Merging

.PHONY : CMakeFiles/334_Merging.dir/build

CMakeFiles/334_Merging.dir/requires: CMakeFiles/334_Merging.dir/main.cpp.o.requires

.PHONY : CMakeFiles/334_Merging.dir/requires

CMakeFiles/334_Merging.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/334_Merging.dir/cmake_clean.cmake
.PHONY : CMakeFiles/334_Merging.dir/clean

CMakeFiles/334_Merging.dir/depend:
	cd /Users/ankoor/Desktop/Programming/DS/334.Merging/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ankoor/Desktop/Programming/DS/334.Merging /Users/ankoor/Desktop/Programming/DS/334.Merging /Users/ankoor/Desktop/Programming/DS/334.Merging/cmake-build-debug /Users/ankoor/Desktop/Programming/DS/334.Merging/cmake-build-debug /Users/ankoor/Desktop/Programming/DS/334.Merging/cmake-build-debug/CMakeFiles/334_Merging.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/334_Merging.dir/depend
