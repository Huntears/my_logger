//
// Created by huntears on 09/10/2020.
//

#include <assert.h>

/// \brief Implementation of strcpy
/// \param dest Copy destination (has to be allocated)
/// \param src Copy source
void my_strcpy(char *dest, char const *src)
{
    assert(dest);
    assert(src);
    for (int i = 0; src[i]; i++)
        dest[i] = src[i];
}