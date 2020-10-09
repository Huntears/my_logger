//
// Created by huntears on 09/10/2020.
//

#include <stdlib.h>
#include <assert.h>

#include "my_logger.h"

/// \brief Implementation of strdup
/// \param str The string to duplicate
/// \return The duplicated string
char *my_strdup(char const *str)
{
    char *dest = NULL;

    assert(str);
    dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    assert(dest);
    my_strcpy(dest, str);
    return (dest);
}