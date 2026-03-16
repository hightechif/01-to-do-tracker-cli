#ifndef TASK_H
#define TASK_H

#define MAX_TASKS 100
#define MAX_DESC 256

typedef struct {
    int id;
    int is_completed;
    char description[MAX_DESC];
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} TaskList;

void task_init(TaskList *list);
int task_add(TaskList *list, const char *description);
int task_delete(TaskList *list, int id);
int task_toggle(TaskList *list, int id);
void task_list_print(const TaskList *list);

#endif
