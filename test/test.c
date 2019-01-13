#include "test.h"

/* Structures */
struct testStatus {
        int total;
        int passed;
        int failed;
};

struct testUnit {
        const char *suite;
        bool passed;
};

/* private prototypes */
bool __assert_double_equals(const double actual, const double expected);
void failed_test_description(const char *file, const char *function,
                             const int line, const char *format, ...);

/* General state */
static struct testStatus testStatus;
static struct testUnit testUnit;

/* Testing functions */
void test_start(void)
{
        testStatus.passed = 0;
        testStatus.failed = 0;
}

void test_suite(const char *name, void (*function)(void))
{
        testUnit.suite = name;
        function();
}

void test(void (*function)(void))
{
        testStatus.total++;
        testUnit.passed = true;
        function();
        if (testUnit.passed) {
                testStatus.passed++;
        } else {
                testStatus.failed++;
        }
}

int test_end(void)
{
        printf("total: %d ", testStatus.total);
        printf(" | ");
        printf("passed: %d ", testStatus.passed);
        printf(" | ");
        printf("failed: %d\n", testStatus.failed);
        return testStatus.failed;
}

/* Assertion functions */
void _assert_double_equals(const double actual, const double expected,
                           const char *file, const char *function,
                           const int line)
{
        bool result = __assert_double_equals(actual, expected);
        if (result) {
                return;
        } else {
                testUnit.passed = false;
                failed_test_description(file, function, line, "%f = %f", actual,
                                        expected);
        }
}

/* Assert */
bool __assert_double_equals(const double actual, const double expected)
{
        if (actual == expected) {
                return true;
        } else {
                return false;
        }
}

void failed_test_description(const char *file, const char *function,
                             const int line, const char *format, ...)
{
        printf("%s#%s:%d: ", file, function, line);
        printf("assertion failed \"");
        va_list argp;
        va_start(argp, format);
        vprintf(format, argp);
        va_end(argp);
        printf("\"\n");
}
