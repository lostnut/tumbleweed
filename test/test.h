#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

static noreturn void assertion_failed();

/* Assertions */
void assert_double_equals(const double actual, const double expected);

