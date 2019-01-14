#include "blas.h"
#include "dryrun.h"

void dasum_test(void);

int main(void)
{
        DRYRUN_START;
        dasum_test();
        return DRYRUN_END;
}
