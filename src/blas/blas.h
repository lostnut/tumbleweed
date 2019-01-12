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
