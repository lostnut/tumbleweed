#include <complex.h>
#include <math.h>

/* Returns the sum of the absolutes values.
 *
 * n: number of elements in x
 * x: vector array
 * incx: increment for indexing vector x
 *
 * return: the sum of the absolutes values
 *
 * error: if n < 0 or n = 0, returns 0
 */
double dasum(const int n, const double *x, const int incx);

/* Computes aX+Y.
 *
 * n: number of elements in x and y
 * a: a scalar
 * x: vector array
 * incx: increment for indexing vector x
 * y: vector array
 * incy: increment for indexing vector y
 *
 * output: y constains the updated vector
 *
 * error: if n < 0 or n = 0, y unchanged
 */
void daxpy(const int n, const double a, const double *x, const int incx,
           double *y, const int incy);
