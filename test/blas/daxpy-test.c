#include "blas.h"
#include "dryrun.h"

void daxpy_negative_length(void)
{
        int n       = -1;
        int incx    = 1;
        int incy    = 1;
        double x[2] = {1.0, 2.0};
        double y[2] = {1.0, 3.0};
        double a    = 1;
        daxpy(n, a, x, incx, y, incy);
        ASSERT_DOUBLE_ARRAY_EQUALS(x, y, 2);
}

void daxpy_test(void)
{
        DRYRUN_TEST(daxpy_negative_length);
}
