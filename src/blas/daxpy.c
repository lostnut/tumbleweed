#include "blas.h"

void daxpy(const int n, const double a, const double *x, const int incx,
           double *y, const int incy)
{
        if (n <= 0) {
                return;
        }
        if (a == 0) {// 0 * x + y = y
                return;
        }
        for (int i = 0, indexx = 0, indexy = 0; i < n;
             i++, indexx += incx, indexy += incy) {
                y[indexy] += x[indexx] * a;
        }
}
