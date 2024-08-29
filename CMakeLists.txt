cmake_minimum_required(VERSION 3.29)
project(c_refresh C)

set(CMAKE_C_STANDARD 11)

add_executable(c_refresh main.c
        linked_list.c
        linked_list.h)
