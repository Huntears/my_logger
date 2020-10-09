//
// Created by huntears on 09/10/2020.
//

#include <criterion/criterion.h>

#include "my_logger.h"

TestSuite(suite_destroy,
          .timeout=10,
          .description="Tests for the logger destruction");

Test(suite_destroy, basic_test_valid_pointer)
{
    logger_t *logger = init_logger(NULL, false, false, false);

    destroy_logger(logger);
}

Test(suite_destroy, valid_filename)
{
    logger_t *logger = init_logger("some_filename", false, false, false);

    destroy_logger(logger);
}

Test(suite_destroy, null_pointer)
{
    destroy_logger(NULL);
}

// 1 is casted to prevent warnings
Test(suite_destroy, invalid_pointer, .signal=11)
{
    destroy_logger((void *)1);
}

// Disabled due to an unnecessary print from free
// Enable this test only if you have major problems with the logger
Test(suite_destroy, invalid_stack_pointer, .signal=16, .disabled=true)
{
    logger_t logger;

    destroy_logger(&logger);
}