cmake_minimum_required(VERSION 3.7)
project(c_1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES week4/targil3/program.c week4/targil3/transposing.h week4/targil3/transposing.c)
add_executable(c_1 ${SOURCE_FILES})