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
CMAKE_BINARY_DIR = /workspaces/test_c/build

# Utility rule file for opencv_java_jar.

# Include the progress variables for this target.
include modules/java/jar/CMakeFiles/opencv_java_jar.dir/progress.make

modules/java/jar/CMakeFiles/opencv_java_jar: bin/opencv-4110.jar


bin/opencv-4110.jar: modules/java/jar/CMakeFiles/opencv_java_jar.dir/java_class_filelist
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/workspaces/test_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Creating Java archive opencv-4110.jar"
	cd /workspaces/test_c/build/modules/java/jar/CMakeFiles/opencv_java_jar.dir && /usr/local/sdkman/candidates/java/current/bin/jar -cfm /workspaces/test_c/build/bin/opencv-4110.jar /workspaces/test_c/build/modules/java/jar/opencv/MANIFEST.MF @java_class_filelist
	cd /workspaces/test_c/build/modules/java/jar/CMakeFiles/opencv_java_jar.dir && /usr/bin/cmake -D_JAVA_TARGET_DIR=/workspaces/test_c/build/bin -D_JAVA_TARGET_OUTPUT_NAME=opencv-4110.jar -D_JAVA_TARGET_OUTPUT_LINK= -P /usr/share/cmake-3.16/Modules/UseJavaSymlinks.cmake

modules/java/jar/CMakeFiles/opencv_java_jar.dir/java_class_filelist: modules/java/jar/CMakeFiles/opencv_java_jar.dir/java_compiled_opencv_java_jar
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/workspaces/test_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CMakeFiles/opencv_java_jar.dir/java_class_filelist"
	cd /workspaces/test_c/image_filter/opencv/modules/java/jar && /usr/bin/cmake -DCMAKE_JAVA_CLASS_OUTPUT_PATH=/workspaces/test_c/build/modules/java/jar/CMakeFiles/opencv_java_jar.dir -DCMAKE_JAR_CLASSES_PREFIX="" -P /usr/share/cmake-3.16/Modules/UseJavaClassFilelist.cmake

modules/java/jar/CMakeFiles/opencv_java_jar.dir/java_compiled_opencv_java_jar: modules/java/jar/opencv/java_sources
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/workspaces/test_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building Java objects for opencv_java_jar.jar"
	cd /workspaces/test_c/image_filter/opencv/modules/java/jar && /usr/local/sdkman/candidates/java/current/bin/javac -encoding utf-8 -classpath :/workspaces/test_c/image_filter/opencv/modules/java/jar:/workspaces/test_c/build/lib -d /workspaces/test_c/build/modules/java/jar/CMakeFiles/opencv_java_jar.dir @/workspaces/test_c/build/modules/java/jar/opencv/java_sources
	cd /workspaces/test_c/image_filter/opencv/modules/java/jar && /usr/bin/cmake -E touch /workspaces/test_c/build/modules/java/jar/CMakeFiles/opencv_java_jar.dir/java_compiled_opencv_java_jar

opencv_java_jar: modules/java/jar/CMakeFiles/opencv_java_jar
opencv_java_jar: bin/opencv-4110.jar
opencv_java_jar: modules/java/jar/CMakeFiles/opencv_java_jar.dir/java_class_filelist
opencv_java_jar: modules/java/jar/CMakeFiles/opencv_java_jar.dir/java_compiled_opencv_java_jar
opencv_java_jar: modules/java/jar/CMakeFiles/opencv_java_jar.dir/build.make

.PHONY : opencv_java_jar

# Rule to build all files generated by this target.
modules/java/jar/CMakeFiles/opencv_java_jar.dir/build: opencv_java_jar

.PHONY : modules/java/jar/CMakeFiles/opencv_java_jar.dir/build

modules/java/jar/CMakeFiles/opencv_java_jar.dir/clean:
	cd /workspaces/test_c/build/modules/java/jar && $(CMAKE_COMMAND) -P CMakeFiles/opencv_java_jar.dir/cmake_clean.cmake
.PHONY : modules/java/jar/CMakeFiles/opencv_java_jar.dir/clean

modules/java/jar/CMakeFiles/opencv_java_jar.dir/depend:
	cd /workspaces/test_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/test_c/image_filter/opencv /workspaces/test_c/image_filter/opencv/modules/java/jar /workspaces/test_c/build /workspaces/test_c/build/modules/java/jar /workspaces/test_c/build/modules/java/jar/CMakeFiles/opencv_java_jar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/java/jar/CMakeFiles/opencv_java_jar.dir/depend

