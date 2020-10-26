//
// Created by huntears on 08/10/2020.
//

#ifndef MY_LOGGER_MY_LOGGER_H
#define MY_LOGGER_MY_LOGGER_H

#include <sys/types.h>
#include <stdbool.h>

enum log_flags {
    log_info = 1,
    log_warning = 1 << 1,
    log_error = 1 << 2,
    log_debug = 1 << 3,
    log_undefined = 15 << 4
};

#define SAFE_FREE(ptr) if (ptr) \
                        free(ptr);

#define SAFE_CLOSE(fd) if (fd > 0) \
                        close(fd);


typedef struct logger_s {
    bool append;
    bool print_to_stdout;
    bool print_to_file;
    char *log_file_name;
    int32_t log_file_fd;
} logger_t;

logger_t *init_logger(char *filename, bool append, bool print_to_stdout, bool print_to_file);
void destroy_logger(logger_t *logger);

// Utility
int my_strlen(char const *str);
char *my_strdup(char const *str);
void my_strcpy(char *dest, char const *src);

#endif //MY_LOGGER_MY_LOGGER_H
