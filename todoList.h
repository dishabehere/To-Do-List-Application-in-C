// todoList.h
#ifndef TODOLIST_H
#define TODOLIST_H

typedef struct {
    int id;
    char title[256];
    char description[512];
} Task;

void addTask();
void displayTasks();
void deleteTask(int id);
void updateTask(int id);
// void saveTasksToFile();
// void loadTasksFromFile();

#endif