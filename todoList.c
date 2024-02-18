// todoList.c
#include "todoList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assume a fixed size for simplicity, dynamic resizing could be implemented later.
// #define MAX_TASKS 100

// Task tasks[MAX_TASKS];
int taskCount = 0;

Task *tasks = NULL; // Pointer to Task array
int taskCapacity = 0;

void ensureCapacity() {
    if (taskCount == taskCapacity) {
        taskCapacity = taskCapacity == 0 ? 10 : taskCapacity * 2; // Initial capacity 10, double when needed
        tasks = realloc(tasks, taskCapacity * sizeof(Task));
        if (tasks == NULL) {
            printf("Failed to allocate memory for tasks.\n");
            exit(1);
        }
    }
}

void addTask() {
    ensureCapacity(); // Ensure there is enough space for a new task
    
    // Create a new Task instance
    Task newTask;
    newTask.id = taskCount + 1; // Simple ID assignment, can be improved for real scenarios.
    
    // Get Task title from user
    printf("Enter title: ");
    fgets(newTask.title, sizeof(newTask.title), stdin);
    newTask.title[strcspn(newTask.title, "\n")] = '\0'; // Remove trailing newline character

    // Get task description from user
    printf("Enter description: ");
    fgets(newTask.description, sizeof(newTask.description), stdin);
    newTask.description[strcspn(newTask.description, "\n")] = 0; //  Remove trailing newline character

    // Add the new Task to our list of tasks
    tasks[taskCount++] = newTask;
    
    printf("Task added successfully with ID %d\n", newTask.id);  
}

void displayTasks() {
    printf("To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d: %s - %s\n", tasks[i].id, tasks[i].title, tasks[i].description);
    }
}

void deleteTask(int id){
    int found = 0;
    for (int i = 0; i < taskCount; i++){
        if (tasks[i].id == id){
            found = 1;
            for (int j = i; j < taskCount - 1; j++){
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            printf("Task %d deleted successfully.\n", id);
            break;
        }   
    }
    if (!found) {
        printf("No such task with ID=%d exists in the system.\n", id);
    }
}

void updateTask(int id){
    int found = 0;
    for (int i = 0; i < taskCount; i++){
        if (tasks[i].id == id){
            found = 1;
            printf("Enter new title: ");
            fgets(tasks[i].title, 256, stdin);
            printf("Enter new description: ");
            fgets(tasks[i].description, 512, stdin);
            printf("Task %d updated successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Task with ID %d not found.\n", id);
    }
}