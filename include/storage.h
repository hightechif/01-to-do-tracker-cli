#ifndef STORAGE_H
#define STORAGE_H

#include "task.h"

#define STORAGE_FILE "tasks.txt"

int storage_save(const TaskList *list);
int storage_load(TaskList *list);

#endif
