cmake_minimum_required(VERSION 3.7)
project(c_1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES week4/targil1/program.c week4/targil1/sorting.h week4/targil1/sorting.c week4/targil1/printing.h week4/targil1/printing.c week4/targil1/maxlength.h week4/targil1/maxlength.c)
add_executable(c_1 ${SOURCE_FILES})