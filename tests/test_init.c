//
// Created by huntears on 08/10/2020.
//

#include <criterion/criterion.h>

#include "my_logger.h"

Test(suite_init, basic_test)
{
    cr_assert_eq(init_logger(), 0);
}