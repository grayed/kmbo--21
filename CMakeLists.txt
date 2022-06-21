# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("kmbo--21")

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
	add_compile_options(/Wall)
	add_compile_options(/wd4668)	# happens inside standard C library
	add_compile_options(/wd5045)	# useless
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_compile_options(-Wall)
endif ()

# Include sub-projects.
add_subdirectory ("classwork")
add_subdirectory ("exam")

add_subdirectory ("animals")
add_subdirectory ("memhacks")
add_subdirectory ("electricity")
add_subdirectory ("vectors")
