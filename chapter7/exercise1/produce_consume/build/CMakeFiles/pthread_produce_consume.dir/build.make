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
CMAKE_SOURCE_DIR = /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/build

# Include any dependencies generated for this target.
include CMakeFiles/pthread_produce_consume.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pthread_produce_consume.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pthread_produce_consume.dir/flags.make

CMakeFiles/pthread_produce_consume.dir/main.cpp.o: CMakeFiles/pthread_produce_consume.dir/flags.make
CMakeFiles/pthread_produce_consume.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pthread_produce_consume.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pthread_produce_consume.dir/main.cpp.o -c /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/main.cpp

CMakeFiles/pthread_produce_consume.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pthread_produce_consume.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/main.cpp > CMakeFiles/pthread_produce_consume.dir/main.cpp.i

CMakeFiles/pthread_produce_consume.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pthread_produce_consume.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/main.cpp -o CMakeFiles/pthread_produce_consume.dir/main.cpp.s

# Object files for target pthread_produce_consume
pthread_produce_consume_OBJECTS = \
"CMakeFiles/pthread_produce_consume.dir/main.cpp.o"

# External object files for target pthread_produce_consume
pthread_produce_consume_EXTERNAL_OBJECTS =

pthread_produce_consume: CMakeFiles/pthread_produce_consume.dir/main.cpp.o
pthread_produce_consume: CMakeFiles/pthread_produce_consume.dir/build.make
pthread_produce_consume: CMakeFiles/pthread_produce_consume.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pthread_produce_consume"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pthread_produce_consume.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pthread_produce_consume.dir/build: pthread_produce_consume

.PHONY : CMakeFiles/pthread_produce_consume.dir/build

CMakeFiles/pthread_produce_consume.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pthread_produce_consume.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pthread_produce_consume.dir/clean

CMakeFiles/pthread_produce_consume.dir/depend:
	cd /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/build /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/build /home/lsp10/Workspace/tasks/books/unpipc/chapter7/exercise1/produce_consume/build/CMakeFiles/pthread_produce_consume.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pthread_produce_consume.dir/depend

