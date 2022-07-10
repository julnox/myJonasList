cmake_minimum_required(VERSION 3.12)
project (myjonaslist C)

set(CMAKE_C_STANDARD 11)

add_executable(myjonaslist main.c menus.c funcoes.c menus.h funcoes.h)