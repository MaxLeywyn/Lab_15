cmake_minimum_required(VERSION 3.26)
project(Lab_15 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab_15 main.c
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/matrix.c)
