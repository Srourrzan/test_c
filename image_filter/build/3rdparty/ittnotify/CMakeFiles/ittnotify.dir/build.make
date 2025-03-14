# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/test_c/image_filter/opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/test_c/image_filter/build

# Include any dependencies generated for this target.
include 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/depend.make

# Include the progress variables for this target.
include 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/progress.make

# Include the compile flags for this target's objects.
include 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/flags.make

3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.o: 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/flags.make
3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.o: /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify/src/ittnotify/ittnotify_static.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/test_c/image_filter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.o"
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.o   -c /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify/src/ittnotify/ittnotify_static.c

3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.i"
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify/src/ittnotify/ittnotify_static.c > CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.i

3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.s"
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify/src/ittnotify/ittnotify_static.c -o CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.s

3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.o: 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/flags.make
3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.o: /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify/src/ittnotify/jitprofiling.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/test_c/image_filter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.o"
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.o   -c /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify/src/ittnotify/jitprofiling.c

3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.i"
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify/src/ittnotify/jitprofiling.c > CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.i

3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.s"
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify/src/ittnotify/jitprofiling.c -o CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.s

# Object files for target ittnotify
ittnotify_OBJECTS = \
"CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.o" \
"CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.o"

# External object files for target ittnotify
ittnotify_EXTERNAL_OBJECTS =

3rdparty/lib/libittnotify.a: 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/ittnotify_static.c.o
3rdparty/lib/libittnotify.a: 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/src/ittnotify/jitprofiling.c.o
3rdparty/lib/libittnotify.a: 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/build.make
3rdparty/lib/libittnotify.a: 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/test_c/image_filter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library ../lib/libittnotify.a"
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && $(CMAKE_COMMAND) -P CMakeFiles/ittnotify.dir/cmake_clean_target.cmake
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ittnotify.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
3rdparty/ittnotify/CMakeFiles/ittnotify.dir/build: 3rdparty/lib/libittnotify.a

.PHONY : 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/build

3rdparty/ittnotify/CMakeFiles/ittnotify.dir/clean:
	cd /workspaces/test_c/image_filter/build/3rdparty/ittnotify && $(CMAKE_COMMAND) -P CMakeFiles/ittnotify.dir/cmake_clean.cmake
.PHONY : 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/clean

3rdparty/ittnotify/CMakeFiles/ittnotify.dir/depend:
	cd /workspaces/test_c/image_filter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/test_c/image_filter/opencv /workspaces/test_c/image_filter/opencv/3rdparty/ittnotify /workspaces/test_c/image_filter/build /workspaces/test_c/image_filter/build/3rdparty/ittnotify /workspaces/test_c/image_filter/build/3rdparty/ittnotify/CMakeFiles/ittnotify.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3rdparty/ittnotify/CMakeFiles/ittnotify.dir/depend

