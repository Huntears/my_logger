//
// Created by huntears on 08/10/2020.
//

#include <criterion/criterion.h>

#include "my_logger.h"

TestSuite(suite_init,
          .timeout=10,
          .description="Tests for the logger initialization");

Test(suite_init, basic_test_all_null)
{
    logger_t *logger = init_logger(NULL, false, false, false);

    cr_assert_neq(logger, NULL);
    cr_assert_eq(logger->log_file_name, NULL);
    cr_assert_eq(logger->log_file_fd, 0);
    cr_assert_eq(logger->print_to_file, false);
    cr_assert_eq(logger->print_to_stdout, false);
    cr_assert_eq(logger->append, false);
}

Test(suite_init, basic_test_filename_set)
{
    logger_t *logger = init_logger("some_filename", false, false, false);

    cr_assert_neq(logger, NULL);
    cr_assert_str_eq(logger->log_file_name, "some_filename");
    cr_assert_eq(logger->log_file_fd, 0);
    cr_assert_eq(logger->print_to_file, false);
    cr_assert_eq(logger->print_to_stdout, false);
    cr_assert_eq(logger->append, false);
}