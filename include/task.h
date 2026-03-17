#ifndef TASK_H
#define TASK_H

#include "type.h"

#define MAX_TASKS 100
#define MAX_DESC 256

typedef struct {
    i32 id;
    b8 is_completed;
    char description[MAX_DESC];
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    i32 count;
} TaskList;

void task_init(TaskList *list);
i32 task_add(TaskList *list, const char *description);
i32 task_delete(TaskList *list, i32 id);
i32 task_toggle(TaskList *list, i32 id);
void task_list_print(const TaskList *list);

#endif
