cmake_minimum_required(VERSION 3.26)
project(optignl C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(optignl
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        main.c
        get_next_line_bonus.h
        get_next_line_bonus.h
        get_next_line_bonus.c)
