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
CMAKE_SOURCE_DIR = /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1_Basic_SDL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1_Basic_SDL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_Basic_SDL.dir/flags.make

CMakeFiles/1_Basic_SDL.dir/main.cpp.o: CMakeFiles/1_Basic_SDL.dir/flags.make
CMakeFiles/1_Basic_SDL.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1_Basic_SDL.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1_Basic_SDL.dir/main.cpp.o -c /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/main.cpp

CMakeFiles/1_Basic_SDL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1_Basic_SDL.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/main.cpp > CMakeFiles/1_Basic_SDL.dir/main.cpp.i

CMakeFiles/1_Basic_SDL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1_Basic_SDL.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/main.cpp -o CMakeFiles/1_Basic_SDL.dir/main.cpp.s

CMakeFiles/1_Basic_SDL.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/1_Basic_SDL.dir/main.cpp.o.requires

CMakeFiles/1_Basic_SDL.dir/main.cpp.o.provides: CMakeFiles/1_Basic_SDL.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/1_Basic_SDL.dir/build.make CMakeFiles/1_Basic_SDL.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/1_Basic_SDL.dir/main.cpp.o.provides

CMakeFiles/1_Basic_SDL.dir/main.cpp.o.provides.build: CMakeFiles/1_Basic_SDL.dir/main.cpp.o


# Object files for target 1_Basic_SDL
1_Basic_SDL_OBJECTS = \
"CMakeFiles/1_Basic_SDL.dir/main.cpp.o"

# External object files for target 1_Basic_SDL
1_Basic_SDL_EXTERNAL_OBJECTS =

1_Basic_SDL: CMakeFiles/1_Basic_SDL.dir/main.cpp.o
1_Basic_SDL: CMakeFiles/1_Basic_SDL.dir/build.make
1_Basic_SDL: /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib
1_Basic_SDL: CMakeFiles/1_Basic_SDL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1_Basic_SDL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1_Basic_SDL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_Basic_SDL.dir/build: 1_Basic_SDL

.PHONY : CMakeFiles/1_Basic_SDL.dir/build

CMakeFiles/1_Basic_SDL.dir/requires: CMakeFiles/1_Basic_SDL.dir/main.cpp.o.requires

.PHONY : CMakeFiles/1_Basic_SDL.dir/requires

CMakeFiles/1_Basic_SDL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1_Basic_SDL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1_Basic_SDL.dir/clean

CMakeFiles/1_Basic_SDL.dir/depend:
	cd /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/cmake-build-debug /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/cmake-build-debug /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/1.Basic-SDL/cmake-build-debug/CMakeFiles/1_Basic_SDL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1_Basic_SDL.dir/depend

