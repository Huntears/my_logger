//
// Created by huntears on 27/10/2020.
//

#include <criterion/criterion.h>

#include "my_logger.h"

TestSuite(suite_my_strlen,
          .timeout=10,
          .description="Tests for the my_strlen utility");

Test(suite_my_strlen, basic_test)
{
    int result = my_strlen("Yes");

    cr_assert_eq(result, 3);
}

Test(suite_my_strlen, empty_string)
{
    int result = my_strlen("");

    cr_assert_eq(result, 0);
}