#include "dryrun-internal.h"

/* structs */
struct dryrunStatus {
        int total;
        int failed;
        int passed;
};

struct dryrunUnit {
        bool passed;
};

/* private prototypes */
void _dryrun_print_results(void);
void _assert_failed(const char *file, const char *function, const int line,
                    const char *format, ...);
bool _assert_true(const int condition);
bool _assert_false(const int condition);
bool _assert_int_equals(const int actual, const int expected);
bool _assert_long_equals(const long actual, const long expected);
bool _assert_float_equals(const float actual, const float expected);
bool _assert_double_equals(const double actual, const double expected);

/* globlas */
static struct dryrunStatus status;
static struct dryrunUnit unit;

void dryrun_start(void)
{
        status.total  = 0;
        status.failed = 0;
        status.passed = 0;
}

void dryrun_test(void (*function)(void))
{
        status.total++;
        unit.passed = true;
        function();
        if (unit.passed) {
                status.passed++;
        } else {
                status.failed++;
        }
}

int dryrun_end(void)
{
        _dryrun_print_results();
        return status.failed;
}

void _dryrun_print_results(void)
{
        fprintf(stdout, "------------------------------------------------------"
                        "--------------------------\n");
        fprintf(stdout, "total: %d\n", status.total);
        fprintf(stdout, "passed: %d\n", status.passed);
        fprintf(stdout, "failed: %d\n", status.failed);
        fprintf(stdout, "------------------------------------------------------"
                        "--------------------------\n");
}

/* Assertions */
void assert_true(const int condition, const char *file, const char *function,
                 const int line)
{
        bool passed = _assert_true(condition);
        if (passed) {
                return;
        } else {
                _assert_failed(file, function, line, "expected TRUE was FALSE");
        }
}

void assert_false(const int condition, const char *file, const char *function,
                  const int line)
{
        bool passed = _assert_false(condition);
        if (passed) {
                return;
        } else {
                _assert_failed(file, function, line, "expected FALSE was TRUE");
        }
}

void assert_int_equals(const int actual, const int expected, const char *file,
                       const char *function, const int line)
{
        bool passed = _assert_int_equals(actual, expected);
        if (passed) {
                return;
        } else {
                _assert_failed(file, function, line, "expected (int)%d was %d",
                               expected, actual);
        }
}

void assert_long_equals(const long actual, const long expected,
                        const char *file, const char *function, const int line)
{
        bool passed = _assert_long_equals(actual, expected);
        if (passed) {
                return;
        } else {
                _assert_failed(file, function, line,
                               "expected (long)%ld was %ld", expected, actual);
        }
}

void assert_float_equals(const float actual, const float expected,
                         const char *file, const char *function, const int line)
{
        bool passed = _assert_float_equals(actual, expected);
        if (passed) {
                return;
        } else {
                _assert_failed(file, function, line,
                               "expected (float)%e was %e", expected, actual);
        }
}

void assert_double_equals(const double actual, const double expected,
                          const char *file, const char *function,
                          const int line)
{
        bool passed = _assert_double_equals(actual, expected);
        if (passed) {
                return;
        } else {
                _assert_failed(file, function, line,
                               "expected (double)%e was %e", expected, actual);
        }
}

/* private functions */
void _assert_failed(const char *file, const char *function, const int line,
                    const char *format, ...)
{
        unit.passed = false;
        fprintf(stdout, "assertion failed \"");
        va_list argp;
        va_start(argp, format);
        vfprintf(stdout, format, argp);
        va_end(argp);
        fprintf(stdout, "\" -> %s#%s:%d\n", file, function, line);
}

bool _assert_true(const int condition)
{
        if (condition) {
                return true;
        } else {
                return false;
        }
}

bool _assert_false(const int condition)
{
        if (condition) {
                return false;
        } else {
                return true;
        }
}

bool _assert_int_equals(const int actual, const int expected)
{
        if (actual == expected) {
                return true;
        } else {
                return false;
        }
}

bool _assert_long_equals(const long actual, const long expected)
{
        if (actual == expected) {
                return true;
        } else {
                return false;
        }
}

bool _assert_float_equals(const float actual, const float expected)
{
        if (actual == expected) {
                return true;
        } else {
                return false;
        }
}

bool _assert_double_equals(const double actual, const double expected)
{
        if (actual == expected) {
                return true;
        } else {
                return false;
        }
}
