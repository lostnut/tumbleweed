#include "blas.h"
#include "test.h"

void dasum_test(void);

int main(void)
{
        test_start();
        test_suite("dasum", dasum_test);
        return test_end();
}
