#include "dryrun-internal.h"

/* Testing workflow */
void dryrun_start(void);
void dryrun_test(void (*function)(void));
int dryrun_end(void);

/* Macro workflow */
#define DRYRUN_START dryrun_start()
#define DRYRUN_TEST(function) dryrun_test(function)
#define DRYRUN_END dryrun_end()

/* Macro assertions */
#define ASSERT_TRUE(condition)                                                 \
        assert_true(condition, __FILE__, __func__, __LINE__)
#define ASSERT_FALSE(condition)                                                \
        assert_false(condition, __FILE__, __func__, __LINE__)
#define ASSERT_INT_EQUALS(actual, expected)                                    \
        assert_int_equals(actual, expected, __FILE__, __func__, __LINE__)
#define ASSERT_LONG_EQUALS(actual, expected)                                   \
        assert_long_equals(actual, expected, __FILE__, __func__, __LINE__)
#define ASSERT_FLOAT_EQUALS(actual, expected)                                  \
        assert_float_equals(actual, expected, __FILE__, __func__, __LINE__)
#define ASSERT_DOUBLE_EQUALS(actual, expected)                                 \
        assert_double_equals(actual, expected, __FILE__, __func__, __LINE__)
#define ASSERT_DOUBLE_ARRAY_EQUALS(actual, expected, length)                   \
        assert_double_array_equals(actual, expected, length, __FILE__,         \
                                   __func__, __LINE__)
