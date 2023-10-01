#ifndef SORT_H
#define SORT_H

using namespace std;

#include <string>
#include <iostream>
#include <algorithm>
#include "task.h"

void sortTasksById(vector<Task> &tasks);
void sortTasksByName(vector<Task> &tasks);
bool sortByTaskName(Task &task1, Task &task2);
bool sortByTaskId(Task &task1, Task &task2);

#endif
