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
CMAKE_SOURCE_DIR = /home/bernardo/Desktop/Generator/Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bernardo/Desktop/Generator/Engine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/class3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/class3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/class3.dir/flags.make

CMakeFiles/class3.dir/main.cpp.o: CMakeFiles/class3.dir/flags.make
CMakeFiles/class3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bernardo/Desktop/Generator/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/class3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/class3.dir/main.cpp.o -c /home/bernardo/Desktop/Generator/Engine/main.cpp

CMakeFiles/class3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/class3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bernardo/Desktop/Generator/Engine/main.cpp > CMakeFiles/class3.dir/main.cpp.i

CMakeFiles/class3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/class3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bernardo/Desktop/Generator/Engine/main.cpp -o CMakeFiles/class3.dir/main.cpp.s

CMakeFiles/class3.dir/tinyxml2.cpp.o: CMakeFiles/class3.dir/flags.make
CMakeFiles/class3.dir/tinyxml2.cpp.o: ../tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bernardo/Desktop/Generator/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/class3.dir/tinyxml2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/class3.dir/tinyxml2.cpp.o -c /home/bernardo/Desktop/Generator/Engine/tinyxml2.cpp

CMakeFiles/class3.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/class3.dir/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bernardo/Desktop/Generator/Engine/tinyxml2.cpp > CMakeFiles/class3.dir/tinyxml2.cpp.i

CMakeFiles/class3.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/class3.dir/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bernardo/Desktop/Generator/Engine/tinyxml2.cpp -o CMakeFiles/class3.dir/tinyxml2.cpp.s

# Object files for target class3
class3_OBJECTS = \
"CMakeFiles/class3.dir/main.cpp.o" \
"CMakeFiles/class3.dir/tinyxml2.cpp.o"

# External object files for target class3
class3_EXTERNAL_OBJECTS =

class3: CMakeFiles/class3.dir/main.cpp.o
class3: CMakeFiles/class3.dir/tinyxml2.cpp.o
class3: CMakeFiles/class3.dir/build.make
class3: /usr/lib/x86_64-linux-gnu/libGL.so
class3: /usr/lib/x86_64-linux-gnu/libGLU.so
class3: /usr/lib/x86_64-linux-gnu/libglut.so
class3: CMakeFiles/class3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bernardo/Desktop/Generator/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable class3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/class3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/class3.dir/build: class3

.PHONY : CMakeFiles/class3.dir/build

CMakeFiles/class3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/class3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/class3.dir/clean

CMakeFiles/class3.dir/depend:
	cd /home/bernardo/Desktop/Generator/Engine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bernardo/Desktop/Generator/Engine /home/bernardo/Desktop/Generator/Engine /home/bernardo/Desktop/Generator/Engine/cmake-build-debug /home/bernardo/Desktop/Generator/Engine/cmake-build-debug /home/bernardo/Desktop/Generator/Engine/cmake-build-debug/CMakeFiles/class3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/class3.dir/depend

