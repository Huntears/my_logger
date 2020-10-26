//
// Created by huntears on 27/10/2020.
//

#include <criterion/criterion.h>

#include "my_logger.h"

TestSuite(suite_my_strcpy,
          .timeout=10,
          .description="Tests for the my_strcpy utility");

Test(suite_my_strcpy, basic_test)
{
    char *result = malloc(sizeof(char) * 4);
    my_strcpy(result, "Yes");

    cr_assert_str_eq(result, "Yes");
}