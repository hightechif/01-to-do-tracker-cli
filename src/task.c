#include <stdio.h>
#include <string.h>
#include "task.h"

void task_init(TaskList *list) {
    list->count = 0;
    list->last_id = 0;
}

i32 task_add(TaskList *list, const char *description) {
    if (list->count >= MAX_TASKS) {
        return -1;
    }
    
    Task *new_task = &list->tasks[list->count];
    list->last_id++;
    new_task->id = list->last_id;
    new_task->is_completed = 0;
    strncpy(new_task->description, description, MAX_DESC - 1);
    new_task->description[MAX_DESC - 1] = '\0';
    
    list->count++;
    return new_task->id;
}

i32 task_delete(TaskList *list, i32 id) {
    i32 found_index = -1;
    for (i32 i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            found_index = i;
            break;
        }
    }
    
    if (found_index == -1) return -1;
    
    // Shift remaining tasks
    for (i32 i = found_index; i < list->count - 1; i++) {
        list->tasks[i] = list->tasks[i + 1];
    }
    
    list->count--;
    return 0;
}

i32 task_toggle(TaskList *list, i32 id) {
    for (i32 i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            list->tasks[i].is_completed = !list->tasks[i].is_completed;
            return 0;
        }
    }
    return -1;
}

void task_list_print(const TaskList *list) {
    if (list->count == 0) {
        printf("No tasks found.\n");
        return;
    }
    
    printf("%-4s %-10s %s\n", "ID", "Status", "Description");
    printf("-------------------------------\n");
    for (i32 i = 0; i < list->count; i++) {
        printf("%-4d %-10s %s\n", 
               list->tasks[i].id, 
               list->tasks[i].is_completed ? "[X]" : "[ ]", 
               list->tasks[i].description);
    }
}
