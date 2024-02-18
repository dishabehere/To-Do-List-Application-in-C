// main.c
#include "todoList.c"
#include <stdio.h>

int main() {
    int choice;

    while (1) {
        printf("\nTo-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Update Task\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to catch newline

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
             case 3:
                printf("Enter task ID to update: ");
                scanf("%d", &choice);
                getchar(); // to catch newline
                updateTask(choice);
                break;
            case 4:
                printf("Enter task ID to delete: ");
                scanf("%d", &choice);
                getchar();
                deleteTask(choice);
                break;
            case 5:
                printf("Exiting application.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    free(tasks);
    return 0;
}