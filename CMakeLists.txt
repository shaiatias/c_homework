cmake_minimum_required(VERSION 3.7)
project(c_1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        exams/2016BB/calcfreq.c)

add_executable(c_1 ${SOURCE_FILES})