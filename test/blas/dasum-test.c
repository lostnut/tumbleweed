#include "blas.h"
#include "test.h"

void dasum_negative_length(void)
{
        double x[2]   = {1, 1};
        int n         = -1;
        int incx      = 1;
        double result = dasum(n, x, incx);
        assert_double_equals(result, 0.0);
}

void dasum_null_length(void)
{
        double x[2]   = {1, 1};
        int n         = 0;
        int incx      = 1;
        double result = dasum(n, x, incx);
        assert_double_equals(result, 0.0);
}

void dasum_unity_increment(void)
{
        double x[2]   = {1.0, 2.0};
        int n         = 2;
        int incx      = 1;
        double result = dasum(n, x, incx);
        assert_double_equals(result, 3.0);
}

void dasum_positive_increment(void)
{
        double x[4]   = {1.0, 2.0, 3.0, 4.0};
        int n         = 2;
        int incx      = 2;
        double result = dasum(n, x, incx);
        assert_double_equals(result, 4.0);
}

void dasum_neg_incremnt(void)
{
        double x[2]   = {1.0, 2.0};
        int n         = 2;
        int incx      = -1;
        double result = dasum(n, (x + 1), incx);
        assert_double_equals(result, 3.0);
}

void dasum_test(void)
{
        test(dasum_negative_length);
        test(dasum_null_length);
        test(dasum_unity_increment);
        test(dasum_positive_increment);
        test(dasum_negative_length);
}

