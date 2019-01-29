#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

/* software testing workflow */
void stStart(void);
void stEnd(void);
void stRunTest(void (*test)(void), const char *file, const char *function,
               const int line);

/* assertion functions */
void stAssert(const int condition, const char *expression, const char *file,
              const char *function, const int line);

/* macros */
/* workflow */
#define ST_START() stStart()
#define ST_RUN_TEST(test) stRunTest(test, __FILE__, #test, __LINE__)
#define ST_END() stEnd()
/* assertions */
#define ST_ASSERT(expression)                                                  \
        stAssert(expression, #expression, __FILE__, __func__, __LINE__)
