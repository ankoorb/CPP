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
CMAKE_SOURCE_DIR = /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/274_LevelOrderTraversal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/274_LevelOrderTraversal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/274_LevelOrderTraversal.dir/flags.make

CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o: CMakeFiles/274_LevelOrderTraversal.dir/flags.make
CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o -c /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/main.cpp

CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/main.cpp > CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.i

CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/main.cpp -o CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.s

CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o.requires

CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o.provides: CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/274_LevelOrderTraversal.dir/build.make CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o.provides

CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o.provides.build: CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o


# Object files for target 274_LevelOrderTraversal
274_LevelOrderTraversal_OBJECTS = \
"CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o"

# External object files for target 274_LevelOrderTraversal
274_LevelOrderTraversal_EXTERNAL_OBJECTS =

274_LevelOrderTraversal: CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o
274_LevelOrderTraversal: CMakeFiles/274_LevelOrderTraversal.dir/build.make
274_LevelOrderTraversal: CMakeFiles/274_LevelOrderTraversal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 274_LevelOrderTraversal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/274_LevelOrderTraversal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/274_LevelOrderTraversal.dir/build: 274_LevelOrderTraversal

.PHONY : CMakeFiles/274_LevelOrderTraversal.dir/build

CMakeFiles/274_LevelOrderTraversal.dir/requires: CMakeFiles/274_LevelOrderTraversal.dir/main.cpp.o.requires

.PHONY : CMakeFiles/274_LevelOrderTraversal.dir/requires

CMakeFiles/274_LevelOrderTraversal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/274_LevelOrderTraversal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/274_LevelOrderTraversal.dir/clean

CMakeFiles/274_LevelOrderTraversal.dir/depend:
	cd /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/cmake-build-debug /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/cmake-build-debug /Users/ankoor/Desktop/Programming/DS/274.LevelOrderTraversal/cmake-build-debug/CMakeFiles/274_LevelOrderTraversal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/274_LevelOrderTraversal.dir/depend
