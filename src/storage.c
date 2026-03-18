#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"
#include "cJSON.h"

i32 storage_save(const TaskList *list, const char *filename) {
    if (!list) return -1;

    cJSON *root = cJSON_CreateObject();
    if (!root) return -1;

    cJSON_AddNumberToObject(root, "last_id", list->last_id);
    
    cJSON *tasks = cJSON_AddArrayToObject(root, "tasks");
    if (!tasks) {
        cJSON_Delete(root);
        return -1;
    }

    for (i32 i = 0; i < list->count; i++) {
        cJSON *task = cJSON_CreateObject();
        if (!task) continue;

        cJSON_AddNumberToObject(task, "id", list->tasks[i].id);
        cJSON_AddNumberToObject(task, "is_completed", list->tasks[i].is_completed);
        cJSON_AddStringToObject(task, "description", list->tasks[i].description);
        
        cJSON_AddItemToArray(tasks, task);
    }

    char *json_str = cJSON_Print(root);
    if (!json_str) {
        cJSON_Delete(root);
        return -1;
    }

    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening storage file for writing");
        cJSON_free(json_str);
        cJSON_Delete(root);
        return -1;
    }

    fputs(json_str, file);
    fclose(file);

    cJSON_free(json_str);
    cJSON_Delete(root);
    return 0;
}

static i32 storage_load_legacy(TaskList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    char line[512];
    list->count = 0;
    list->last_id = 0;

    while (fgets(line, sizeof(line), file) && list->count < MAX_TASKS) {
        if (line[0] == '#') {
            if (sscanf(line, "# LAST_ID:%d", &list->last_id) == 1) {
                continue;
            }
            continue;
        }

        Task *t = &list->tasks[list->count];
        char *id_str = strtok(line, "|");
        char *status_str = strtok(NULL, "|");
        char *desc_str = strtok(NULL, "\n");
        
        if (id_str && status_str && desc_str) {
            t->id = atoi(id_str);
            t->is_completed = atoi(status_str);
            strncpy(t->description, desc_str, MAX_DESC - 1);
            t->description[MAX_DESC - 1] = '\0';
            
            if (t->id > list->last_id) {
                list->last_id = t->id;
            }
            
            list->count++;
        }
    }
    
    fclose(file);
    return 0;
}

i32 storage_load(TaskList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return 0;

    // Check if JSON or legacy
    int first_char = fgetc(file);
    if (first_char == EOF) {
        fclose(file);
        return 0;
    }

    if (first_char == '#') {
        fclose(file);
        return storage_load_legacy(list, filename);
    }

    ungetc(first_char, file);
    
    // Read the whole file into memory
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = (char *)malloc(length + 1);
    if (!data) {
        fclose(file);
        return -1;
    }

    size_t read_len = fread(data, 1, length, file);
    data[read_len] = '\0';
    fclose(file);

    cJSON *root = cJSON_Parse(data);
    free(data);

    if (!root) {
        // Fallback or error? Let's try legacy if parsing fails?
        // Actually, let's just error if we think it's JSON but fails parsing.
        return -1;
    }

    cJSON *last_id = cJSON_GetObjectItem(root, "last_id");
    if (cJSON_IsNumber(last_id)) {
        list->last_id = last_id->valueint;
    }

    cJSON *tasks = cJSON_GetObjectItem(root, "tasks");
    if (cJSON_IsArray(tasks)) {
        int tasks_count = cJSON_GetArraySize(tasks);
        list->count = 0;
        for (int i = 0; i < tasks_count && i < MAX_TASKS; i++) {
            cJSON *task = cJSON_GetArrayItem(tasks, i);
            if (!task) continue;

            cJSON *id = cJSON_GetObjectItem(task, "id");
            cJSON *status = cJSON_GetObjectItem(task, "is_completed");
            cJSON *desc = cJSON_GetObjectItem(task, "description");

            if (cJSON_IsNumber(id) && cJSON_IsNumber(status) && cJSON_IsString(desc)) {
                list->tasks[list->count].id = id->valueint;
                list->tasks[list->count].is_completed = (i8)status->valueint;
                strncpy(list->tasks[list->count].description, desc->valuestring, MAX_DESC - 1);
                list->tasks[list->count].description[MAX_DESC - 1] = '\0';
                list->count++;
            }
        }
    }

    cJSON_Delete(root);
    return 0;
}
