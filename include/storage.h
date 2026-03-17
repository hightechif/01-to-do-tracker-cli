#ifndef STORAGE_H
#define STORAGE_H

#include "task.h"
#include "type.h"

#define DEFAULT_STORAGE_FILE "tasks.txt"

i32 storage_save(const TaskList *list, const char *filename);
i32 storage_load(TaskList *list, const char *filename);

#endif
