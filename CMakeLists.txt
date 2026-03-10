cmake_minimum_required(VERSION 3.31)
project(LeetCode LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS
    ON
    CACHE BOOL "" FORCE)

add_executable(main main.cpp)
