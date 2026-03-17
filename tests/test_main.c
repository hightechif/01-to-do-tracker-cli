#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "test_harness.h"

// Define global test state
i32 tests_run = 0;
i32 tests_failed = 0;

// Test prototypes
void test_task_add();
void test_task_delete();
void test_task_toggle();
void test_task_id_uniqueness();
void test_storage_save_load();

i32 main() {
    printf("Starting Unit Tests...\n");
    printf("--------------------\n");

    RUN_TEST(test_task_add);
    RUN_TEST(test_task_delete);
    RUN_TEST(test_task_toggle);
    RUN_TEST(test_task_id_uniqueness);
    RUN_TEST(test_storage_save_load);

    printf("--------------------\n");
    printf("Summary: %d tests run, %d failed.\n", tests_run, tests_failed);

    if (tests_failed > 0) {
        printf("FAILED\n");
        return 1;
    } else {
        printf("ALL TESTS PASSED\n");
        return 0;
    }
}
