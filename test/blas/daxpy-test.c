#include "blas.h"
#include "dryrun.h"

void daxpy_negative_length(void)
{
        int n       = -1;
        int incx    = 1;
        int incy    = 1;
        double x[2] = {1.0, 2.0};
        double y[2] = {1.0, 2.0};
        double a    = 1;
        daxpy(n, a, x, incx, y, incy);
        ASSERT_DOUBLE_ARRAY_EQUALS(y, x, 2);
}

void daxpy_null_length(void)
{
        int n       = 0;
        int incx    = 1;
        int incy    = 1;
        double x[2] = {1.0, 2.0};
        double y[2] = {1.0, 2.0};
        double a    = 1;
        daxpy(n, a, x, incx, y, incy);
        ASSERT_DOUBLE_ARRAY_EQUALS(y, x, 2);
}

void daxpy_null_alpha(void)
{
        int n       = 2;
        int incx    = 1;
        int incy    = 1;
        double x[2] = {1.0, 2.0};
        double y[2] = {1.0, 2.0};
        double a    = 0;
        daxpy(n, a, x, incx, y, incy);
        ASSERT_DOUBLE_ARRAY_EQUALS(y, x, 2);
}

void daxpy_normal(void)
{
        int n       = 2;
        int incx    = 1;
        int incy    = 1;
        double x[2] = {1.0, 2.0};
        double y[2] = {1.0, 2.0};
        double a    = 2;
        double r[2] = {3.0, 6.0};
        daxpy(n, a, x, incx, y, incy);
        ASSERT_DOUBLE_ARRAY_EQUALS(y, r, 2);
}

void daxpy_test(void)
{
        DRYRUN_TEST(daxpy_negative_length);
        DRYRUN_TEST(daxpy_null_length);
        DRYRUN_TEST(daxpy_null_alpha);
        DRYRUN_TEST(daxpy_normal);
}
