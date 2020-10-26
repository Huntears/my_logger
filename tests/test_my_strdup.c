//
// Created by huntears on 27/10/2020.
//

#include <criterion/criterion.h>

#include "my_logger.h"

TestSuite(suite_my_strdup,
          .timeout=10,
          .description="Tests for the my_strdup utility");

Test(suite_my_strdup, basic_test)
{
    char *result = my_strdup("Yes");

    cr_assert_str_eq(result, "Yes");
}