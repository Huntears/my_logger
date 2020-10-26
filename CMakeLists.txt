cmake_minimum_required(VERSION 3.17)
project(my_logger)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include/)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(my_logger include/my_logger.h src/init.c tests/test_init.c src/utility/my_strlen.c src/utility/my_strdup.c src/utility/my_strcpy.c src/destroy.c tests/test_destroy.c src/log.c src/utility/my_fputstr.c tests/test_log.c tests/test_my_strlen.c)
target_link_libraries(my_logger criterion)