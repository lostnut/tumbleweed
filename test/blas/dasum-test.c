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

void dasum_test(void)
{
        test(dasum_negative_length);
        test(dasum_null_length);
}

