# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/bernardo/Desktop/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/bernardo/Desktop/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Engine.dir/flags.make

CMakeFiles/Engine.dir/main.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Engine.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/main.cpp.o -c /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/main.cpp

CMakeFiles/Engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/main.cpp > CMakeFiles/Engine.dir/main.cpp.i

CMakeFiles/Engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/main.cpp -o CMakeFiles/Engine.dir/main.cpp.s

CMakeFiles/Engine.dir/tinyxml2.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/tinyxml2.cpp.o: ../tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Engine.dir/tinyxml2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/tinyxml2.cpp.o -c /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/tinyxml2.cpp

CMakeFiles/Engine.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/tinyxml2.cpp > CMakeFiles/Engine.dir/tinyxml2.cpp.i

CMakeFiles/Engine.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/tinyxml2.cpp -o CMakeFiles/Engine.dir/tinyxml2.cpp.s

CMakeFiles/Engine.dir/engine.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/engine.cpp.o: ../engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Engine.dir/engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/engine.cpp.o -c /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/engine.cpp

CMakeFiles/Engine.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/engine.cpp > CMakeFiles/Engine.dir/engine.cpp.i

CMakeFiles/Engine.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/engine.cpp -o CMakeFiles/Engine.dir/engine.cpp.s

CMakeFiles/Engine.dir/sg.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/sg.cpp.o: ../sg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Engine.dir/sg.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/sg.cpp.o -c /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/sg.cpp

CMakeFiles/Engine.dir/sg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/sg.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/sg.cpp > CMakeFiles/Engine.dir/sg.cpp.i

CMakeFiles/Engine.dir/sg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/sg.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/sg.cpp -o CMakeFiles/Engine.dir/sg.cpp.s

# Object files for target Engine
Engine_OBJECTS = \
"CMakeFiles/Engine.dir/main.cpp.o" \
"CMakeFiles/Engine.dir/tinyxml2.cpp.o" \
"CMakeFiles/Engine.dir/engine.cpp.o" \
"CMakeFiles/Engine.dir/sg.cpp.o"

# External object files for target Engine
Engine_EXTERNAL_OBJECTS =

Engine: CMakeFiles/Engine.dir/main.cpp.o
Engine: CMakeFiles/Engine.dir/tinyxml2.cpp.o
Engine: CMakeFiles/Engine.dir/engine.cpp.o
Engine: CMakeFiles/Engine.dir/sg.cpp.o
Engine: CMakeFiles/Engine.dir/build.make
Engine: /usr/lib/x86_64-linux-gnu/libGL.so
Engine: /usr/lib/x86_64-linux-gnu/libGLU.so
Engine: /usr/lib/x86_64-linux-gnu/libglut.so
Engine: CMakeFiles/Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Engine.dir/build: Engine

.PHONY : CMakeFiles/Engine.dir/build

CMakeFiles/Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Engine.dir/clean

CMakeFiles/Engine.dir/depend:
	cd /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug /home/bernardo/Desktop/Universidade/CG/Trabalho/CG18-19/Engine/cmake-build-debug/CMakeFiles/Engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Engine.dir/depend

