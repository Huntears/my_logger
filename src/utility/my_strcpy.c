//
// Created by huntears on 09/10/2020.
//

#include <assert.h>

void my_strcpy(char *dest, char const *src)
{
    assert(dest);
    assert(src);
    for (int i = 0; src[i]; i++)
        dest[i] = src[i];
}