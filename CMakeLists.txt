# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("kmbo--21")

# Include sub-projects.
add_subdirectory ("classwork")
add_subdirectory ("animals")
add_subdirectory ("memhacks")
add_subdirectory ("electricity")
add_subdirectory ("vectors")
