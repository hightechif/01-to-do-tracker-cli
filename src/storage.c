#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

int storage_save(const TaskList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening storage file for writing");
        return -1;
    }
    
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%d|%d|%s\n", 
                list->tasks[i].id, 
                list->tasks[i].is_completed, 
                list->tasks[i].description);
    }
    
    fclose(file);
    return 0;
}

int storage_load(TaskList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0; // Not an error, just no tasks yet
    
    char line[512];
    list->count = 0;
    while (fgets(line, sizeof(line), file) && list->count < MAX_TASKS) {
        Task *t = &list->tasks[list->count];
        char *id_str = strtok(line, "|");
        char *status_str = strtok(NULL, "|");
        char *desc_str = strtok(NULL, "\n");
        
        if (id_str && status_str && desc_str) {
            t->id = atoi(id_str);
            t->is_completed = atoi(status_str);
            strncpy(t->description, desc_str, MAX_DESC - 1);
            t->description[MAX_DESC - 1] = '\0';
            list->count++;
        }
    }
    
    fclose(file);
    return 0;
}
