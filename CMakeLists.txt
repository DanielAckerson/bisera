cmake_minimum_required(VERSION 3.7.2 FATAL_ERROR)

project(bisera)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra)

option(BISERA_BUILD_EXAMPLES "Build the bisera example programs." ON)
option(BISERA_BUILD_TESTS "Build the bisera test programs." ON)

find_package(glfw3 3.2 REQUIRED)
find_package(Threads REQUIRED)

add_library(glad OBJECT deps/glad.c)
add_library(lodepng OBJECT deps/lodepng.cpp)
include_directories(deps)

include_directories(include)
add_subdirectory(src)

if(BISERA_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(BISERA_BUILD_TESTS)
    add_subdirectory(tests)
endif()
