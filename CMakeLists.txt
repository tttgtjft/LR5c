cmake_minimum_required(VERSION 3.20)
project(LR5c C)

set(CMAKE_C_STANDARD 11)

add_executable(LR5c main.c)

add_library(sort sort/sort.h sort/sort.c
        sort/time_test/time_test.h sort/time_test/time_test.c)

target_link_libraries(LR5c sort)
