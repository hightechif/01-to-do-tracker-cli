#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "storage.h"
#include "type.h"
#include "test_harness.h"

#define TEST_FILE "/tmp/test_tasks.txt"

void test_storage_save_load() {
    TaskList list;
    task_init(&list);
    task_add(&list, "Save me");
    task_add(&list, "Me too");
    
    i32 res = storage_save(&list, TEST_FILE);
    ASSERT("Storage save should succeed", res == 0);
    
    TaskList loaded_list;
    task_init(&loaded_list);
    res = storage_load(&loaded_list, TEST_FILE);
    ASSERT("Storage load should succeed", res == 0);
    ASSERT("Loaded count should match", loaded_list.count == 2);
    ASSERT("First task should match", strcmp(loaded_list.tasks[0].description, "Save me") == 0);
    ASSERT("Second task should match", strcmp(loaded_list.tasks[1].description, "Me too") == 0);
    
    // Cleanup
    unlink(TEST_FILE);
}
