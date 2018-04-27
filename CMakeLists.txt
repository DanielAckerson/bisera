cmake_minimum_required(VERSION 3.7.2 FATAL_ERROR)

project(bisera)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(glfw3 3.2 REQUIRED)
find_package(Threads REQUIRED)
find_package(PNG REQUIRED)

add_subdirectory(bisera-client)
add_subdirectory(tests)
