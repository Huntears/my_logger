//
// Created by huntears on 26/10/2020.
//

#include <unistd.h>

#include "my_logger.h"

void my_fputstr(char const *str, int fd)
{
    write(fd, str, my_strlen(str));
}