//
// Created by huntears on 26/10/2020.
//

#include "my_logger.h"

const char* levels[4] = {
        "[INFO] ",
        "[WARNING] ",
        "[ERROR] ",
        "[DEBUG] "
};

// Yes I know this function is absolutely hideous
// Yes I'll change it later, but for now it'll do
static void print_levels(int log_flags, int fd)
{
    if (log_flags & log_info)
        my_fputstr(levels[0], fd);
    if (log_flags & log_warning)
        my_fputstr(levels[1], fd);
    if (log_flags & log_error)
        my_fputstr(levels[2], fd);
    if (log_flags & log_debug)
        my_fputstr(levels[3], fd);
}

void log_msg(logger_t *logger, char *msg, int log_flags)
{
    if (logger->print_to_file) {
        print_levels(log_flags, logger->log_file_fd);
        my_fputstr(msg, logger->log_file_fd);
    }
    if (logger->print_to_stdout) {
        print_levels(log_flags, 1);
        my_fputstr(msg, 1);
    }
}