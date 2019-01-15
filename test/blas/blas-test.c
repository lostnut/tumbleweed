#include "blas.h"
#include "dryrun.h"

void dasum_test(void);
void daxpy_test(void);

int main(void)
{
        DRYRUN_START;
        dasum_test();
        daxpy_test();
        return DRYRUN_END;
}
