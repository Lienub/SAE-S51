#ifndef SORT_H
#define SORT_H

using namespace std;

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "task.h"

void sortTasksById(vector<Task> &tasks);
bool sortByTaskId(Task &task1, Task &task2);

void sortTasksByName(vector<Task> &tasks);
bool sortByTaskName(Task &task1, Task &task2);

void sortTasksByDescription(vector<Task> &tasks);
bool sortTaskByDescription(Task &task1, Task &task2);

void sortTasksByStartDate(vector<Task> &tasks);
bool sortTaskByStartDate(Task &task1, Task &task2);

void sortTasksByEndDate(vector<Task> &tasks);
bool sortTaskByEndDate(Task &task1, Task &task2);

void sortTasksByPriority(vector<Task> &tasks);
bool sortTaskByPriority(Task &task1, Task &task2);

#endif
