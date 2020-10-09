//
// Created by huntears on 09/10/2020.
//

#include <stdlib.h>
#include <unistd.h>

#include "my_logger.h"

/// \brief Destroys the logger
/// \param logger The logger to destroy
void destroy_logger(logger_t *logger)
{
    if (!logger)
        return;
    SAFE_FREE(logger->log_file_name);
    SAFE_CLOSE(logger->log_file_fd);
    free(logger);
}