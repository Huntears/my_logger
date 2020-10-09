//
// Created by huntears on 09/10/2020.
//

#include <assert.h>

/// \brief Implementation of strlen
/// \param str The string to get the length
/// \return The length of str
int my_strlen(char const *str)
{
    int i = 0;

    assert(str);
    while (str[i++]);
    return (i);
}