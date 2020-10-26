//
// Created by huntears on 26/10/2020.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my_logger.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}

TestSuite(suite_log,
          .timeout=10,
          .description="Tests for the logger");

Test(suite_log, print_stdout_no_file_no_flag, .init=redirect_all_stdout)
{
    logger_t *logger = init_logger(NULL, false, true, false);

    cr_assert_neq(logger, NULL);
    cr_assert_eq(logger->log_file_name, NULL);
    cr_assert_eq(logger->log_file_fd, 0);
    cr_assert_eq(logger->print_to_file, false);
    cr_assert_eq(logger->print_to_stdout, true);
    cr_assert_eq(logger->append, false);

    log_msg(logger, "Test message", 0);

    cr_assert_stdout_eq_str("Test message");
}

Test(suite_log, print_stdout_no_file_debug_flag, .init=redirect_all_stdout)
{
    logger_t *logger = init_logger(NULL, false, true, false);

    cr_assert_neq(logger, NULL);
    cr_assert_eq(logger->log_file_name, NULL);
    cr_assert_eq(logger->log_file_fd, 0);
    cr_assert_eq(logger->print_to_file, false);
    cr_assert_eq(logger->print_to_stdout, true);
    cr_assert_eq(logger->append, false);

    log_msg(logger, "Test message", log_debug);

    cr_assert_stdout_eq_str("[DEBUG] Test message");
}

Test(suite_log, print_stdout_no_file_debug_warning_flag, .init=redirect_all_stdout)
{
    logger_t *logger = init_logger(NULL, false, true, false);

    cr_assert_neq(logger, NULL);
    cr_assert_eq(logger->log_file_name, NULL);
    cr_assert_eq(logger->log_file_fd, 0);
    cr_assert_eq(logger->print_to_file, false);
    cr_assert_eq(logger->print_to_stdout, true);
    cr_assert_eq(logger->append, false);

    log_msg(logger, "Test message", log_debug | log_warning);

    cr_assert_stdout_eq_str("[WARNING] [DEBUG] Test message");
}

Test(suite_log, print_stdout_no_file_all_flag, .init=redirect_all_stdout)
{
    logger_t *logger = init_logger(NULL, false, true, false);

    cr_assert_neq(logger, NULL);
    cr_assert_eq(logger->log_file_name, NULL);
    cr_assert_eq(logger->log_file_fd, 0);
    cr_assert_eq(logger->print_to_file, false);
    cr_assert_eq(logger->print_to_stdout, true);
    cr_assert_eq(logger->append, false);

    log_msg(logger, "Test message", log_debug | log_warning | log_info | log_error);

    cr_assert_stdout_eq_str("[INFO] [WARNING] [ERROR] [DEBUG] Test message");
}