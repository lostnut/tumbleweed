#include "test.h"

static noreturn void assertion_failed()
{
        fprintf(stdout, "assertion failed");
        exit(EXIT_FAILURE);
}
