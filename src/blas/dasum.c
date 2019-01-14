#include <stdio.h>
#include "blas.h"

double dasum(const int n, const double *x, const int incx)
{
        if (n <= 0) {
                return 0;
        }
        double sum = 0.0;
        for (int i = 0, index = 0; i < n; i++, index += incx) {
                sum += fabs(x[index]);
        }
        return sum;
}
