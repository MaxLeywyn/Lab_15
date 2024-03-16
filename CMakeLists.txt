cmake_minimum_required(VERSION 3.26)
project(Lab_15 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab_15 main.c
        libs/data_structures/matrix/matrix.h
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix_test/matrix_test.h
        libs/data_structures/matrix_test/matrix_test.c
        libs/data_structures/matrix_tasks/matrix_tasks.h
        libs/data_structures/matrix_tasks/matrix_tasks.c)
