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
CMAKE_COMMAND = /home/mohamed/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/mohamed/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mohamed/Dev/C++/ConsoleProjects/Backlog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohamed/Dev/C++/ConsoleProjects/Backlog/build

# Include any dependencies generated for this target.
include CMakeFiles/backlog.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/backlog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/backlog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/backlog.dir/flags.make

CMakeFiles/backlog.dir/main.cpp.o: CMakeFiles/backlog.dir/flags.make
CMakeFiles/backlog.dir/main.cpp.o: /home/mohamed/Dev/C++/ConsoleProjects/Backlog/main.cpp
CMakeFiles/backlog.dir/main.cpp.o: CMakeFiles/backlog.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mohamed/Dev/C++/ConsoleProjects/Backlog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/backlog.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/backlog.dir/main.cpp.o -MF CMakeFiles/backlog.dir/main.cpp.o.d -o CMakeFiles/backlog.dir/main.cpp.o -c /home/mohamed/Dev/C++/ConsoleProjects/Backlog/main.cpp

CMakeFiles/backlog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/backlog.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohamed/Dev/C++/ConsoleProjects/Backlog/main.cpp > CMakeFiles/backlog.dir/main.cpp.i

CMakeFiles/backlog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/backlog.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohamed/Dev/C++/ConsoleProjects/Backlog/main.cpp -o CMakeFiles/backlog.dir/main.cpp.s

# Object files for target backlog
backlog_OBJECTS = \
"CMakeFiles/backlog.dir/main.cpp.o"

# External object files for target backlog
backlog_EXTERNAL_OBJECTS =

backlog: CMakeFiles/backlog.dir/main.cpp.o
backlog: CMakeFiles/backlog.dir/build.make
backlog: CMakeFiles/backlog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mohamed/Dev/C++/ConsoleProjects/Backlog/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable backlog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/backlog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/backlog.dir/build: backlog
.PHONY : CMakeFiles/backlog.dir/build

CMakeFiles/backlog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/backlog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/backlog.dir/clean

CMakeFiles/backlog.dir/depend:
	cd /home/mohamed/Dev/C++/ConsoleProjects/Backlog/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohamed/Dev/C++/ConsoleProjects/Backlog /home/mohamed/Dev/C++/ConsoleProjects/Backlog /home/mohamed/Dev/C++/ConsoleProjects/Backlog/build /home/mohamed/Dev/C++/ConsoleProjects/Backlog/build /home/mohamed/Dev/C++/ConsoleProjects/Backlog/build/CMakeFiles/backlog.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/backlog.dir/depend
