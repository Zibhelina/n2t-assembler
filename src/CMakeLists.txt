cmake_minimum_required(VERSION 3.10)
project(assembler)
add_executable(assembler main.c linked_list/linked_list.c decode/decode.c validate/validate.c)