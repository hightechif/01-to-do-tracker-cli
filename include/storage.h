#ifndef STORAGE_H
#define STORAGE_H

#include "task.h"

#define DEFAULT_STORAGE_FILE "tasks.txt"

int storage_save(const TaskList *list, const char *filename);
int storage_load(TaskList *list, const char *filename);

#endif
