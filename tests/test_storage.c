#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "storage.h"
#include "type.h"
#include "test_harness.h"

#define TEST_FILE "/tmp/test_tasks.json"

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

void test_storage_migration() {
    FILE *file = fopen(TEST_FILE, "w");
    fprintf(file, "# LAST_ID:10\n");
    fprintf(file, "1|0|Legacy Task 1\n");
    fprintf(file, "2|1|Legacy Task 2\n");
    fclose(file);
    
    TaskList list;
    task_init(&list);
    i32 res = storage_load(&list, TEST_FILE);
    ASSERT("Legacy storage load should succeed", res == 0);
    ASSERT("Legacy count should match", list.count == 2);
    ASSERT("Legacy LAST_ID should match", list.last_id == 10);
    ASSERT("First legacy task should match", strcmp(list.tasks[0].description, "Legacy Task 1") == 0);
    ASSERT("First legacy task ID should match", list.tasks[0].id == 1);
    ASSERT("First legacy task status should match", list.tasks[0].is_completed == 0);
    ASSERT("Second legacy task status should match", list.tasks[1].is_completed == 1);
    
    // Save as JSON now
    res = storage_save(&list, TEST_FILE);
    ASSERT("JSON storage save should succeed", res == 0);
    
    // Load back JSON
    TaskList json_list;
    task_init(&json_list);
    res = storage_load(&json_list, TEST_FILE);
    ASSERT("JSON storage load should succeed", res == 0);
    ASSERT("JSON count should match", json_list.count == 2);
    ASSERT("JSON last_id should match", json_list.last_id == 10);
    ASSERT("JSON first task should match", strcmp(json_list.tasks[0].description, "Legacy Task 1") == 0);
    
    unlink(TEST_FILE);
}
