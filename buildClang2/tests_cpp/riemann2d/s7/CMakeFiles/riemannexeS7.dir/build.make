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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2

# Include any dependencies generated for this target.
include tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/depend.make

# Include the progress variables for this target.
include tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/progress.make

# Include the compile flags for this target's objects.
include tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/flags.make

tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/__/main.cc.o: tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/flags.make
tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/__/main.cc.o: ../tests_cpp/riemann2d/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/__/main.cc.o"
	cd /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/riemann2d/s7 && /usr/local/opt/llvm@9/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/riemannexeS7.dir/__/main.cc.o -c /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/riemann2d/main.cc

tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/__/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/riemannexeS7.dir/__/main.cc.i"
	cd /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/riemann2d/s7 && /usr/local/opt/llvm@9/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/riemann2d/main.cc > CMakeFiles/riemannexeS7.dir/__/main.cc.i

tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/__/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/riemannexeS7.dir/__/main.cc.s"
	cd /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/riemann2d/s7 && /usr/local/opt/llvm@9/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/riemann2d/main.cc -o CMakeFiles/riemannexeS7.dir/__/main.cc.s

# Object files for target riemannexeS7
riemannexeS7_OBJECTS = \
"CMakeFiles/riemannexeS7.dir/__/main.cc.o"

# External object files for target riemannexeS7
riemannexeS7_EXTERNAL_OBJECTS =

tests_cpp/riemann2d/s7/riemannexeS7: tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/__/main.cc.o
tests_cpp/riemann2d/s7/riemannexeS7: tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/build.make
tests_cpp/riemann2d/s7/riemannexeS7: tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable riemannexeS7"
	cd /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/riemann2d/s7 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/riemannexeS7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/build: tests_cpp/riemann2d/s7/riemannexeS7

.PHONY : tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/build

tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/clean:
	cd /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/riemann2d/s7 && $(CMAKE_COMMAND) -P CMakeFiles/riemannexeS7.dir/cmake_clean.cmake
.PHONY : tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/clean

tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/depend:
	cd /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/riemann2d/s7 /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2 /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/riemann2d/s7 /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests_cpp/riemann2d/s7/CMakeFiles/riemannexeS7.dir/depend

