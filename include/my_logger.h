//
// Created by huntears on 08/10/2020.
//

#ifndef MY_LOGGER_MY_LOGGER_H
#define MY_LOGGER_MY_LOGGER_H

#include <sys/types.h>
#include <stdbool.h>

#define LOG_INFO      0b00000001
#define LOG_WARNING   0b00000010
#define LOG_ERROR     0b00000100
#define LOG_DEBUG     0b00001000
#define LOG_UNDEFINED 0b11110000

typedef struct logger_s {
    bool append;
    bool print_to_stdout;
    bool print_to_file;
    char *log_file_name;
    int32_t log_file_fd;
} logger_t;

logger_t *init_logger(char *filename, bool append, bool print_to_stdout, bool print_to_file);

// Utility
int my_strlen(char const *str);
char *my_strdup(char const *str);
void my_strcpy(char *dest, char const *src);

#endif //MY_LOGGER_MY_LOGGER_H
