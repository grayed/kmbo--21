# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("kmbo--21")



add_executable (memhacks memhacks.cpp)
add_executable (electricity "electricity.cpp" "electricity.h")
# Include sub-projects.
add_subdirectory ("classwork")
add_subdirectory ("animals")
add_subdirectory ("memhacks")
add_subdirectory ("electricity")
add_subdirectory ("vectors")

add_executable(memhacks memhacks.cpp)
