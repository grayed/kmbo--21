# CMakeList.txt : CMake project for containers, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("containers")

# Add source to this project's executable.
add_executable (containers "containers.cpp" "containers.h")

# TODO: Add tests and install targets if needed.
