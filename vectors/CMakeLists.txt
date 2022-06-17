# CMakeList.txt : CMake project for animals, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (vectors "vector.cpp" "../cmake-build-debug/vectors/vector.h")
add_executable (arrays  "array.cpp" "array.h")

# TODO: Add tests and install targets if needed.
