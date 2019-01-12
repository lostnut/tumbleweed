#include "blas.h"
#include "test.h"

void dasum_negative_n()
{
        double x[2]   = {1, 1};
        int n         = -1;
        int incx      = 1;
        double result = dasum(n, x, incx);
        assert_double_equals(result, 0.0);
}

void dasum_test(void)
{
        dasum_negative_n();
}

