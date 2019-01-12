#include "test.h"

static noreturn void assertion_failed()
{
        fprintf(stdout, "assertion failed\n");
        exit(EXIT_FAILURE);
}

void assert_double_equals(const double actual, const double expected)
{
        if (actual == expected) {
                return;
        } else {
                assertion_failed();
        }
}
