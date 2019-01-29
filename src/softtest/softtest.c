#include "softtest.h"

static const char stPassed[] = "\033[32mPASSED\033[00m";
static const char stFailed[] = "\033[31mFAILED\033[00m";

struct StStatus {
        int total;
        int failures;
        int succeeds;
        bool passed;
        struct timespec start;
        struct timespec end;
};

void stStartTest(void);
void stEndTest(const char *file, const char *function, const int line);
void stPrintSucceed(const char *file, const char *function, const int line,
                    const double time);
void stPrintFailure(const char *file, const char *function, const int line,
                    const double time);
void stPrintPass(void);
void stPrintFail(void);
void stPrintElapsedTime(const double time);
void stAssertionFailed(const char *file, const char *function, const int line,
                       const char *format, ...);

static struct StStatus status;

void stStart(void)
{
        status.total    = 0;
        status.failures = 0;
        status.succeeds = 0;
}

void stEnd(void)
{
}

void stRunTest(void (*test)(void), const char *file, const char *function,
               const int line)
{
        stStartTest();
        test();
        stEndTest(file, function, line);
}

void stStartTest(void)
{
        status.total++;
        status.passed = true;
        clock_gettime(CLOCK_REALTIME, &status.start);
}

void stEndTest(const char *file, const char *function, const int line)
{
        clock_gettime(CLOCK_REALTIME, &status.end);
        double elapsed = (status.end.tv_sec - status.start.tv_sec) +
                         (status.end.tv_nsec - status.start.tv_nsec) / 1.0E9;
        if (status.passed) {
                status.succeeds++;
                stPrintSucceed(file, function, line, elapsed);
        } else {
                status.failures++;
                stPrintFailure(file, function, line, elapsed);
        }
}

void stAssert(const int condition, const char *expression, const char *file,
              const char *function, const int line)
{
        if (!condition) {
                stAssertionFailed(file, function, line, "%s evaluated to false",
                                  expression);
        }
}

void stAssertionFailed(const char *file, const char *function, const int line,
                       const char *format, ...)
{
        status.passed = false;
        printf("%s#%s(%d): ", file, function, line);
        va_list arg;
        va_start(arg, format);
        vprintf(format, arg);
        va_end(arg);
        printf("\n");
}

void stPrintSucceed(const char *file, const char *function, const int line,
                    const double time)
{
        stPrintPass();
        printf(" ");
        stPrintElapsedTime(time);
        printf(" ");
        printf("%s:%d: %s\n", time, file, line, function);
}

void stPrintPass(void)
{
        printf("[%s]", stPassed);
}

void stPrintFailure(const char *file, const char *function, const int line,
                    const double time)
{
        stPrintFail();
        printf(" ");
        stPrintElapsedTime(time);
        printf(" ");
        printf("%s:%d: %s\n", file, line, function);
}

void stPrintFail(void)
{
        printf("[%s]", stFailed);
}

void stPrintElapsedTime(const double time)
{
        if (time > 1e0) {
                printf("[%.3lf s]", time);
        } else if (time > 1e-3) {
                printf("[%.3lf ms]", time * 1000);
        } else if (time > 1e-6) {
                printf("[%.3lf µs]", time * 1e6);
        } else {
                printf("[%.3lf ns]", time * 1e9);
        }
}

