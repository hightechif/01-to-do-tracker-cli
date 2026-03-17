#ifndef TEST_HARNESS_H
#define TEST_HARNESS_H

#include <stdio.h>
#include "type.h"

extern i32 tests_run;
extern i32 tests_failed;

#define ASSERT(message, test) do { \
    tests_run++; \
    if (!(test)) { \
        printf("[FAIL] %s:%d: %s\n", __FILE__, __LINE__, message); \
        tests_failed++; \
        return; \
    } \
} while (0)

#define RUN_TEST(test) do { \
    printf("Running %s...\n", #test); \
    test(); \
} while (0)

#endif
