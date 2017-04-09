cmake_minimum_required(VERSION 3.7)
project(c_1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES week1/targil2/program.c week1/myHeaders.h week1/myLibs/createNumByIdx.c week1/myLibs/getMax.c week1/myLibs/getLength.c week1/myLibs/reverseNumber.c week1/myLibs/isBegginingOfWord.c week1/myLibs/isNewLine.c)
add_executable(c_1 ${SOURCE_FILES})