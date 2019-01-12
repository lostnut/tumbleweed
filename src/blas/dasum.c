#include "blas.h"

double dasum(const int n, const double *x, const int incx)
{
        if (n <= 0) {
                return 0;
        }
        double sum = 0.0;
        int final  = n * incx;
        for (int i = 0; i < final; i += incx) {
                sum += fabs(x[i]);
        }
        return sum;
}
