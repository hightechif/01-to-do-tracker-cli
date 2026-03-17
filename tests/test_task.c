#include <assert.h>
#include <string.h>
#include "task.h"
#include "type.h"
#include "test_harness.h"

void test_task_add() {
    TaskList list;
    task_init(&list);
    
    i32 id1 = task_add(&list, "Buy milk");
    ASSERT("Task ID should be 1", id1 == 1);
    ASSERT("List count should be 1", list.count == 1);
    ASSERT("Description should match", strcmp(list.tasks[0].description, "Buy milk") == 0);
    
    i32 id2 = task_add(&list, "Clean room");
    ASSERT("Task ID should be 2", id2 == 2);
    ASSERT("List count should be 2", list.count == 2);
}

void test_task_delete() {
    TaskList list;
    task_init(&list);
    task_add(&list, "Task 1");
    task_add(&list, "Task 2");
    
    i32 res = task_delete(&list, 1);
    ASSERT("Delete task 1 should succeed", res == 0);
    ASSERT("List count should be 1", list.count == 1);
    ASSERT("Remaining task should be 'Task 2'", strcmp(list.tasks[0].description, "Task 2") == 0);
    
    res = task_delete(&list, 99);
    ASSERT("Delete non-existent task should fail", res == -1);
}

void test_task_toggle() {
    TaskList list;
    task_init(&list);
    task_add(&list, "Toggle me");
    
    ASSERT("Initially not completed", list.tasks[0].is_completed == 0);
    
    i32 res = task_toggle(&list, 1);
    ASSERT("Toggle should succeed", res == 0);
    ASSERT("Should be completed", list.tasks[0].is_completed == 1);
    
    task_toggle(&list, 1);
    ASSERT("Should be back to not completed", list.tasks[0].is_completed == 0);
}

void test_task_id_uniqueness() {
    TaskList list;
    task_init(&list);
    
    i32 id1 = task_add(&list, "First Task");
    i32 id2 = task_add(&list, "Second Task");
    ASSERT("ID 1 should be 1", id1 == 1);
    ASSERT("ID 2 should be 2", id2 == 2);
    
    task_delete(&list, 1);
    ASSERT("Count should be 1 after delete", list.count == 1);
    
    i32 id3 = task_add(&list, "Third Task");
    ASSERT("ID 3 should be 3, not 2 (bug fix verification)", id3 == 3);
}
