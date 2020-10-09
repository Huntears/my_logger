//
// Created by huntears on 08/10/2020.
//

#include <stdlib.h>
#include <assert.h>

#include "my_logger.h"

logger_t *init_logger(char *filename, bool append, bool print_to_stdout, bool print_to_file)
{
    logger_t *logger = malloc(sizeof(logger_t));

    assert(logger);
    logger->log_file_fd = 0;
    filename ? logger->log_file_name = my_strdup(filename) : NULL;
    logger->append = append;
    logger->print_to_file = print_to_file;
    logger->print_to_stdout = print_to_stdout;
    return (logger);
}