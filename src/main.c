#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "storage.h"

void print_usage() {
    printf("To-Do Tracker CLI\n");
    printf("Usage:\n");
    printf("  todo add \"description\"  - Add a new task\n");
    printf("  todo list               - List all tasks\n");
    printf("  todo done <id>          - Mark a task as complete\n");
    printf("  todo delete <id>        - Delete a task\n");
    printf("  todo help               - Show this help message\n");
}

int main(int argc, char *argv[]) {
    TaskList list;
    task_init(&list);
    storage_load(&list);

    if (argc < 2) {
        print_usage();
        return 0;
    }

    char *command = argv[1];

    if (strcmp(command, "add") == 0) {
        if (argc < 3) {
            printf("Error: Missing description for 'add' command.\n");
            return 1;
        }
        int id = task_add(&list, argv[2]);
        if (id != -1) {
            storage_save(&list);
            printf("Task added with ID: %d\n", id);
        } else {
            printf("Error: Could not add task.\n");
        }
    } else if (strcmp(command, "list") == 0) {
        task_list_print(&list);
    } else if (strcmp(command, "done") == 0) {
        if (argc < 3) {
            printf("Error: Missing ID for 'done' command.\n");
            return 1;
        }
        int id = atoi(argv[2]);
        if (task_toggle(&list, id) == 0) {
            storage_save(&list);
            printf("Task %d updated.\n", id);
        } else {
            printf("Error: Task %d not found.\n", id);
        }
    } else if (strcmp(command, "delete") == 0) {
        if (argc < 3) {
            printf("Error: Missing ID for 'delete' command.\n");
            return 1;
        }
        int id = atoi(argv[2]);
        if (task_delete(&list, id) == 0) {
            storage_save(&list);
            printf("Task %d deleted.\n", id);
        } else {
            printf("Error: Task %d not found.\n", id);
        }
    } else if (strcmp(command, "help") == 0) {
        print_usage();
    } else {
        printf("Error: Unknown command '%s'\n", command);
        print_usage();
        return 1;
    }

    return 0;
}
