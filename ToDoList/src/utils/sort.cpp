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
    // Sort by name here
    sort(tasks.begin(), tasks.end(), sortByTaskName);
    
}

/**
 * @brief Sorts the tasks by name
 * 
 * @param task1 first task
 * @param task2 second task
 * 
 * @return true if name of task1 is lower than name of task2
 * @return false if name of task 1 is greater than name of task 2
 */
bool sortByTaskName(Task &task1, Task &task2)
{
    return task1.getName() <= task2.getName();
}

/**
 * @brief Sorts the tasks by name
 *
 * This function sortrs the tasks by name
 *
 * @param tasks tasks to sort
 */
void sortTasksByDescription(vector<Task> &tasks)
{
    sort(tasks.begin(), tasks.end(), sortByTaskName);
}

/**
 * @brief Sorts the tasks by description
 * 
 * @param task1 first task
 * @param task2 second task
 * 
 * @return true if description is alphabetically lower than description of task2
 * @return false if description is alphabetically greater than description of task2
 */
bool sortTaskByDescription(Task &task1, Task &task2)
{
    return task1.getDescription() <= task2.getDescription();
}

/**
 * @brief Sorts the tasks by start description
 *
 * This function sortrs the tasks by start date
 *
 * @param tasks tasks to sort
 */
void sortTasksByStartDate(vector<Task> &tasks)
{
    // Sort by name here
    sort(tasks.begin(), tasks.end(), sortByTaskStartDate);
}

/**
 * @brief Sorts the tasks by start date
 * 
 * @param task1 first task
 * @param task2 second task
 * 
 * @return true if start date of task1 is lower than start date of task2
 * @return false if start date of task 1 is greater than start date of task 2
 */
bool sortByTaskStartDate(Task &task1, Task &task2)
{
    return task1.getStartDate() <= task2.getStartDate();
}

/**
 * @brief Sorts the tasks by end date
 *
 * This function sortrs the tasks by end date
 *
 * @param tasks tasks to sort
 */
void sortTasksByEndDate(vector<Task> &tasks)
{
    sort(tasks.begin(), tasks.end(), sortByTaskName);
    
}

/**
 * @brief Sorts the tasks by end date
 * 
 * @param task1 first task
 * @param task2 second task
 * 
 * @return true if end date of task1 is lower than end date of task2
 * @return false if end date of task 1 is greater than end date of task 2
 */
bool sortTasksByEndDate(Task &task1, Task &task2)
{
    return task1.getEndDate() <= task2.getEndDate();
}

/**
 * @brief Sorts the tasks by priority
 *
 * This function sortrs the tasks by priority
 *
 * @param tasks tasks to sort
 */
void sortTasksByPriority(vector<Task> &tasks)
{
    sort(tasks.begin(), tasks.end(), sortByTaskName);
    
}

/**
 * @todo
 */
bool sortByTaskPriority(Task &task1, Task &task2)
{
 
}
