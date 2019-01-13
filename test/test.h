#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

/* Assert macros */
#define assert_double_equals(actual, expected)                                 \
        _assert_double_equals(actual, expected, __FILE__, __func__, __LINE__)

/* Testing function */
void test_start(void);
void test_suite(const char *name, void (*function)(void));
void test(void (*function)(void));
int test_end(void);

/* Assertion functions */
void _assert_double_equals(const double actual, const double expected,
                           const char *file, const char *function,
                           const int line);

