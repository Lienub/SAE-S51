#include "../../includes/sort.h"

/**
 * @brief Sorts the tasks by id
 *
 * This function sortrs the tasks by id
 *
 * @param tasks tasks to sort
 */
void sortTasksById(vector<Task> &tasks)
{
    sort(tasks.begin(), tasks.end(), sortByTaskId);
}

/**
 * @brief Sorts the tasks by id
 * 
 * @param task1 first task
 * @param task2 second task
 * 
 * @return true if ID of task1 is lower than ID of task2
 * @return false if ID of task 1 is greater than ID of task 2
*/
bool sortByTaskId(Task &task1, Task &task2)
{
    return task1.getId() <= task2.getId();
}

/**
 * @brief Sorts the tasks by name
 *
 * This function sortrs the tasks by name
 *
 * @param tasks tasks to sort
 */
void sortTasksByName(vector<Task> &tasks)
{
    
}