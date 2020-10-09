cmake_minimum_required(VERSION 3.17)
project(my_logger)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include/)

add_executable(my_logger include/my_logger.h src/init.c tests/test_init.c src/utility/my_strlen.c src/utility/my_strdup.c src/utility/my_strcpy.c)
target_link_libraries(my_logger criterion)