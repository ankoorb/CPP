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
CMAKE_SOURCE_DIR = /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/272_IterativeTreeTraversals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/272_IterativeTreeTraversals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/272_IterativeTreeTraversals.dir/flags.make

CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o: CMakeFiles/272_IterativeTreeTraversals.dir/flags.make
CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o -c /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/main.cpp

CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/main.cpp > CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.i

CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/main.cpp -o CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.s

CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o.requires

CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o.provides: CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/272_IterativeTreeTraversals.dir/build.make CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o.provides

CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o.provides.build: CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o


# Object files for target 272_IterativeTreeTraversals
272_IterativeTreeTraversals_OBJECTS = \
"CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o"

# External object files for target 272_IterativeTreeTraversals
272_IterativeTreeTraversals_EXTERNAL_OBJECTS =

272_IterativeTreeTraversals: CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o
272_IterativeTreeTraversals: CMakeFiles/272_IterativeTreeTraversals.dir/build.make
272_IterativeTreeTraversals: CMakeFiles/272_IterativeTreeTraversals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 272_IterativeTreeTraversals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/272_IterativeTreeTraversals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/272_IterativeTreeTraversals.dir/build: 272_IterativeTreeTraversals

.PHONY : CMakeFiles/272_IterativeTreeTraversals.dir/build

CMakeFiles/272_IterativeTreeTraversals.dir/requires: CMakeFiles/272_IterativeTreeTraversals.dir/main.cpp.o.requires

.PHONY : CMakeFiles/272_IterativeTreeTraversals.dir/requires

CMakeFiles/272_IterativeTreeTraversals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/272_IterativeTreeTraversals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/272_IterativeTreeTraversals.dir/clean

CMakeFiles/272_IterativeTreeTraversals.dir/depend:
	cd /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/cmake-build-debug /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/cmake-build-debug /Users/ankoor/Desktop/Programming/DS/272.IterativeTreeTraversals/cmake-build-debug/CMakeFiles/272_IterativeTreeTraversals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/272_IterativeTreeTraversals.dir/depend
