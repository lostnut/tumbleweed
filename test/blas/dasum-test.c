#include "blas.h"
#include "dryrun.h"

void dasum_negative_length(void)
{
        double x[2]   = {1, 1};
        int n         = -1;
        int incx      = 1;
        double result = dasum(n, x, incx);
        ASSERT_DOUBLE_EQUALS(result, 0.0);
}

void dasum_null_length(void)
{
        double x[2]   = {1, 1};
        int n         = 0;
        int incx      = 1;
        double result = dasum(n, x, incx);
        ASSERT_DOUBLE_EQUALS(result, 0.0);
}

void dasum_unity_increment(void)
{
        double x[2]   = {1.0, 2.0};
        int n         = 2;
        int incx      = 1;
        double result = dasum(n, x, incx);
        ASSERT_DOUBLE_EQUALS(result, 3.0);
}

void dasum_positive_increment(void)
{
        double x[4]   = {1.0, 2.0, 3.0, 4.0};
        int n         = 2;
        int incx      = 2;
        double result = dasum(n, x, incx);
        ASSERT_DOUBLE_EQUALS(result, 4.0);
}

void dasum_neg_increment(void)
{
        double x[2]   = {1.0, 2.0};
        int n         = 2;
        int incx      = -1;
        double result = dasum(n, (x + 1), incx);
        ASSERT_DOUBLE_EQUALS(result, 3.0);
}

void dasum_test(void)
{
        DRYRUN_TEST(dasum_negative_length);
        DRYRUN_TEST(dasum_null_length);
        DRYRUN_TEST(dasum_unity_increment);
        DRYRUN_TEST(dasum_positive_increment);
        DRYRUN_TEST(dasum_neg_increment);
}

