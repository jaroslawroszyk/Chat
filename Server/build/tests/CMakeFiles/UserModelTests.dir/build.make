# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake-3.27.0-rc3-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.27.0-rc3-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jarek/cpp/chat/Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jarek/cpp/chat/Server/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/UserModelTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/UserModelTests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/UserModelTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/UserModelTests.dir/flags.make

tests/CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o: tests/CMakeFiles/UserModelTests.dir/flags.make
tests/CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o: /home/jarek/cpp/chat/Server/tests/UserModelTests.cpp
tests/CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o: tests/CMakeFiles/UserModelTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jarek/cpp/chat/Server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o"
	cd /home/jarek/cpp/chat/Server/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o -MF CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o.d -o CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o -c /home/jarek/cpp/chat/Server/tests/UserModelTests.cpp

tests/CMakeFiles/UserModelTests.dir/UserModelTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/UserModelTests.dir/UserModelTests.cpp.i"
	cd /home/jarek/cpp/chat/Server/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jarek/cpp/chat/Server/tests/UserModelTests.cpp > CMakeFiles/UserModelTests.dir/UserModelTests.cpp.i

tests/CMakeFiles/UserModelTests.dir/UserModelTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/UserModelTests.dir/UserModelTests.cpp.s"
	cd /home/jarek/cpp/chat/Server/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jarek/cpp/chat/Server/tests/UserModelTests.cpp -o CMakeFiles/UserModelTests.dir/UserModelTests.cpp.s

# Object files for target UserModelTests
UserModelTests_OBJECTS = \
"CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o"

# External object files for target UserModelTests
UserModelTests_EXTERNAL_OBJECTS =

tests/UserModelTests: tests/CMakeFiles/UserModelTests.dir/UserModelTests.cpp.o
tests/UserModelTests: tests/CMakeFiles/UserModelTests.dir/build.make
tests/UserModelTests: tests/CMakeFiles/UserModelTests.dir/compiler_depend.ts
tests/UserModelTests: lib/libgtest_main.a
tests/UserModelTests: libClient.a
tests/UserModelTests: lib/libgtest.a
tests/UserModelTests: tests/CMakeFiles/UserModelTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jarek/cpp/chat/Server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UserModelTests"
	cd /home/jarek/cpp/chat/Server/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UserModelTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/UserModelTests.dir/build: tests/UserModelTests
.PHONY : tests/CMakeFiles/UserModelTests.dir/build

tests/CMakeFiles/UserModelTests.dir/clean:
	cd /home/jarek/cpp/chat/Server/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/UserModelTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/UserModelTests.dir/clean

tests/CMakeFiles/UserModelTests.dir/depend:
	cd /home/jarek/cpp/chat/Server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jarek/cpp/chat/Server /home/jarek/cpp/chat/Server/tests /home/jarek/cpp/chat/Server/build /home/jarek/cpp/chat/Server/build/tests /home/jarek/cpp/chat/Server/build/tests/CMakeFiles/UserModelTests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/UserModelTests.dir/depend
