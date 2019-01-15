#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

/* Testing workflow */
void dryrun_start(void);
void dryrun_test(void (*function)(void));
int dryrun_end(void);

/* Generic assertion */
void assert_true(const int condition, const char *file, const char *function,
                 const int line);
void assert_false(const int condition, const char *file, const char *function,
                  const int line);
/* Equals assertion */
void assert_int_equals(const int actual, const int expected, const char *file,
                       const char *function, const int line);
void assert_long_equals(const long actual, const long expected,
                        const char *file, const char *function, const int line);
void assert_float_equals(const float actual, const float expected,
                         const char *file, const char *function,
                         const int line);
void assert_double_equals(const double actual, const double expected,
                          const char *file, const char *function,
                          const int line);
void assert_double_array_equals(const double *actual, const double *expected,
                                const int length, const char *file,
                                const char *function, const int line);
