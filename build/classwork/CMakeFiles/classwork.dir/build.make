# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/Programms/C++/kmbo--21

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/Programms/C++/kmbo--21/build

# Include any dependencies generated for this target.
include classwork/CMakeFiles/classwork.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include classwork/CMakeFiles/classwork.dir/compiler_depend.make

# Include the progress variables for this target.
include classwork/CMakeFiles/classwork.dir/progress.make

# Include the compile flags for this target's objects.
include classwork/CMakeFiles/classwork.dir/flags.make

classwork/CMakeFiles/classwork.dir/main.cpp.obj: classwork/CMakeFiles/classwork.dir/flags.make
classwork/CMakeFiles/classwork.dir/main.cpp.obj: ../classwork/main.cpp
classwork/CMakeFiles/classwork.dir/main.cpp.obj: classwork/CMakeFiles/classwork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Programms/C++/kmbo--21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object classwork/CMakeFiles/classwork.dir/main.cpp.obj"
	cd D:/Programms/C++/kmbo--21/build/classwork && C:/Users/Ilya/gcc/bin/x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT classwork/CMakeFiles/classwork.dir/main.cpp.obj -MF CMakeFiles/classwork.dir/main.cpp.obj.d -o CMakeFiles/classwork.dir/main.cpp.obj -c D:/Programms/C++/kmbo--21/classwork/main.cpp

classwork/CMakeFiles/classwork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/classwork.dir/main.cpp.i"
	cd D:/Programms/C++/kmbo--21/build/classwork && C:/Users/Ilya/gcc/bin/x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Programms/C++/kmbo--21/classwork/main.cpp > CMakeFiles/classwork.dir/main.cpp.i

classwork/CMakeFiles/classwork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/classwork.dir/main.cpp.s"
	cd D:/Programms/C++/kmbo--21/build/classwork && C:/Users/Ilya/gcc/bin/x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Programms/C++/kmbo--21/classwork/main.cpp -o CMakeFiles/classwork.dir/main.cpp.s

# Object files for target classwork
classwork_OBJECTS = \
"CMakeFiles/classwork.dir/main.cpp.obj"

# External object files for target classwork
classwork_EXTERNAL_OBJECTS =

classwork/classwork.exe: classwork/CMakeFiles/classwork.dir/main.cpp.obj
classwork/classwork.exe: classwork/CMakeFiles/classwork.dir/build.make
classwork/classwork.exe: classwork/CMakeFiles/classwork.dir/linklibs.rsp
classwork/classwork.exe: classwork/CMakeFiles/classwork.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/Programms/C++/kmbo--21/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable classwork.exe"
	cd D:/Programms/C++/kmbo--21/build/classwork && "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f CMakeFiles/classwork.dir/objects.a
	cd D:/Programms/C++/kmbo--21/build/classwork && C:/Users/Ilya/gcc/bin/ar.exe cr CMakeFiles/classwork.dir/objects.a @CMakeFiles/classwork.dir/objects1.rsp
	cd D:/Programms/C++/kmbo--21/build/classwork && C:/Users/Ilya/gcc/bin/x86_64-w64-mingw32-g++.exe -g -Wl,--whole-archive CMakeFiles/classwork.dir/objects.a -Wl,--no-whole-archive -o classwork.exe -Wl,--out-implib,libclasswork.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/classwork.dir/linklibs.rsp

# Rule to build all files generated by this target.
classwork/CMakeFiles/classwork.dir/build: classwork/classwork.exe
.PHONY : classwork/CMakeFiles/classwork.dir/build

classwork/CMakeFiles/classwork.dir/clean:
	cd D:/Programms/C++/kmbo--21/build/classwork && $(CMAKE_COMMAND) -P CMakeFiles/classwork.dir/cmake_clean.cmake
.PHONY : classwork/CMakeFiles/classwork.dir/clean

classwork/CMakeFiles/classwork.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Programms/C++/kmbo--21 D:/Programms/C++/kmbo--21/classwork D:/Programms/C++/kmbo--21/build D:/Programms/C++/kmbo--21/build/classwork D:/Programms/C++/kmbo--21/build/classwork/CMakeFiles/classwork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : classwork/CMakeFiles/classwork.dir/depend

