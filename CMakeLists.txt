cmake_minimum_required(VERSION 3.17)
project(my_logger)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include/)

add_executable(my_logger src/main.c)
