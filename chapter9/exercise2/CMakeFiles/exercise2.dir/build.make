# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lsp/Workspace/unpipc/chapter9/exercise2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lsp/Workspace/unpipc/chapter9/exercise2

# Include any dependencies generated for this target.
include CMakeFiles/exercise2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise2.dir/flags.make

CMakeFiles/exercise2.dir/main.c.o: CMakeFiles/exercise2.dir/flags.make
CMakeFiles/exercise2.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp/Workspace/unpipc/chapter9/exercise2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/exercise2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/exercise2.dir/main.c.o -c /home/lsp/Workspace/unpipc/chapter9/exercise2/main.c

CMakeFiles/exercise2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/exercise2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lsp/Workspace/unpipc/chapter9/exercise2/main.c > CMakeFiles/exercise2.dir/main.c.i

CMakeFiles/exercise2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/exercise2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lsp/Workspace/unpipc/chapter9/exercise2/main.c -o CMakeFiles/exercise2.dir/main.c.s

# Object files for target exercise2
exercise2_OBJECTS = \
"CMakeFiles/exercise2.dir/main.c.o"

# External object files for target exercise2
exercise2_EXTERNAL_OBJECTS =

exercise2: CMakeFiles/exercise2.dir/main.c.o
exercise2: CMakeFiles/exercise2.dir/build.make
exercise2: CMakeFiles/exercise2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lsp/Workspace/unpipc/chapter9/exercise2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable exercise2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exercise2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise2.dir/build: exercise2

.PHONY : CMakeFiles/exercise2.dir/build

CMakeFiles/exercise2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exercise2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exercise2.dir/clean

CMakeFiles/exercise2.dir/depend:
	cd /home/lsp/Workspace/unpipc/chapter9/exercise2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lsp/Workspace/unpipc/chapter9/exercise2 /home/lsp/Workspace/unpipc/chapter9/exercise2 /home/lsp/Workspace/unpipc/chapter9/exercise2 /home/lsp/Workspace/unpipc/chapter9/exercise2 /home/lsp/Workspace/unpipc/chapter9/exercise2/CMakeFiles/exercise2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exercise2.dir/depend

