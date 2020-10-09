//
// Created by huntears on 09/10/2020.
//

#include <assert.h>

int my_strlen(char const *str)
{
    int i = 0;

    assert(str);
    while (str[i++]);
    return (i);
}