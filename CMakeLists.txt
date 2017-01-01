
# CMake configuration for Dynamic_Static_Core

cmake_minimum_required (VERSION 3.2)

project(Dynamic_Static_Core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(
    DYNAMIC_STATIC_CORE_INCLUDE
    ${CMAKE_SOURCE_DIR}/Dynamic_Static_Core/include/
)

add_subdirectory(Dynamic_Static_Core)
add_subdirectory(Sandbox)
add_subdirectory(Tests)