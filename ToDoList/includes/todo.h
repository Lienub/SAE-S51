#ifndef TODO_H
#define TODO_H

#include "task.h"
#include "sort.h"
#include "json_helper.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

/**
 * @brief Display the list of tasks
 *
 * This function displays the list of tasks and
 * sorts according to the option the user has set
 *
 * @param ifstream The input file
 * @param typeSort The type of sorting
 */
void displayTasks(ifstream &file, string typeSort);
/**
 * @brief Display a task
 *
 * This function displays a task
 *
 * @param inputFile The input file
 * @param id The id of the task
 */
void displayTask(ifstream &inputFile, int id);

/**
 * @brief Delete task by id
 *
 * This function delete a task by id
 *
 * @param inputFile The input file
 * @param id The id of the task
 */
json deleteTask(ifstream &file, int id);

Task createTask(ifstream &inputFile, ofstream &outputFile);

#endif
