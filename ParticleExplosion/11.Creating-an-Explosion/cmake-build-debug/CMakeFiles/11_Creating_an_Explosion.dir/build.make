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
CMAKE_SOURCE_DIR = /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/11_Creating_an_Explosion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/11_Creating_an_Explosion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/11_Creating_an_Explosion.dir/flags.make

CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o: CMakeFiles/11_Creating_an_Explosion.dir/flags.make
CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o -c /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/main.cpp

CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/main.cpp > CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.i

CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/main.cpp -o CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.s

CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o.requires

CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o.provides: CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/11_Creating_an_Explosion.dir/build.make CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o.provides

CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o.provides.build: CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o


CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o: CMakeFiles/11_Creating_an_Explosion.dir/flags.make
CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o: ../Screen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o -c /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Screen.cpp

CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Screen.cpp > CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.i

CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Screen.cpp -o CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.s

CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o.requires:

.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o.requires

CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o.provides: CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o.requires
	$(MAKE) -f CMakeFiles/11_Creating_an_Explosion.dir/build.make CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o.provides.build
.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o.provides

CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o.provides.build: CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o


CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o: CMakeFiles/11_Creating_an_Explosion.dir/flags.make
CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o: ../Swarm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o -c /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Swarm.cpp

CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Swarm.cpp > CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.i

CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Swarm.cpp -o CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.s

CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o.requires:

.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o.requires

CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o.provides: CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o.requires
	$(MAKE) -f CMakeFiles/11_Creating_an_Explosion.dir/build.make CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o.provides.build
.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o.provides

CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o.provides.build: CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o


CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o: CMakeFiles/11_Creating_an_Explosion.dir/flags.make
CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o: ../Particle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o -c /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Particle.cpp

CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Particle.cpp > CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.i

CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/Particle.cpp -o CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.s

CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o.requires:

.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o.requires

CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o.provides: CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o.requires
	$(MAKE) -f CMakeFiles/11_Creating_an_Explosion.dir/build.make CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o.provides.build
.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o.provides

CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o.provides.build: CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o


# Object files for target 11_Creating_an_Explosion
11_Creating_an_Explosion_OBJECTS = \
"CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o" \
"CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o" \
"CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o" \
"CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o"

# External object files for target 11_Creating_an_Explosion
11_Creating_an_Explosion_EXTERNAL_OBJECTS =

11_Creating_an_Explosion: CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o
11_Creating_an_Explosion: CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o
11_Creating_an_Explosion: CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o
11_Creating_an_Explosion: CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o
11_Creating_an_Explosion: CMakeFiles/11_Creating_an_Explosion.dir/build.make
11_Creating_an_Explosion: /usr/local/Cellar/sdl2/2.0.8/lib/libSDL2.dylib
11_Creating_an_Explosion: CMakeFiles/11_Creating_an_Explosion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable 11_Creating_an_Explosion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/11_Creating_an_Explosion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/11_Creating_an_Explosion.dir/build: 11_Creating_an_Explosion

.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/build

CMakeFiles/11_Creating_an_Explosion.dir/requires: CMakeFiles/11_Creating_an_Explosion.dir/main.cpp.o.requires
CMakeFiles/11_Creating_an_Explosion.dir/requires: CMakeFiles/11_Creating_an_Explosion.dir/Screen.cpp.o.requires
CMakeFiles/11_Creating_an_Explosion.dir/requires: CMakeFiles/11_Creating_an_Explosion.dir/Swarm.cpp.o.requires
CMakeFiles/11_Creating_an_Explosion.dir/requires: CMakeFiles/11_Creating_an_Explosion.dir/Particle.cpp.o.requires

.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/requires

CMakeFiles/11_Creating_an_Explosion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/11_Creating_an_Explosion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/clean

CMakeFiles/11_Creating_an_Explosion.dir/depend:
	cd /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug /Users/ankoor/Desktop/Programming/C++/ParticleExplosion/11.Creating-an-Explosion/cmake-build-debug/CMakeFiles/11_Creating_an_Explosion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/11_Creating_an_Explosion.dir/depend
