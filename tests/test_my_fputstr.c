//
// Created by huntears on 27/10/2020.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_logger.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

TestSuite(suite_my_fputstr,
          .timeout=10,
          .description="Tests for the my_fputstr utility",
          .init=redirect_all_stdout);

Test(suite_my_fputstr, print_basic)
{
    my_fputstr("Test message", 1);

    cr_assert_stdout_eq_str("Test message");
}