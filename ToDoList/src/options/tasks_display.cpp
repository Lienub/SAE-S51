#include "../../includes/task.h"
#include "../../json_helper.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

/**
 * @brief Display the list of tasks
 *
 * This function displays the list of tasks and
 * sorts according to the option the user has set
 *
 * @param inputFile The input file
 * @param typeSort The type of sorting
 */
void displayTasks(ofstream &inputFile, string typeSort)
{

    json taskJson;
    vector<Task> tasks;
    while (inputFile >> taskJson)
    {
        Task task = JSONHelper::jsonToTask(taskJson);
        tasks.push_back(task);
    }

    for (Task task : tasks)
    {
        string priority = task.getPriority() == Priority::HIGH ? "HIGH" : (task.getPriority() == Priority::MEDIUM ? "MEDIUM" : "LOW");
        cout << "ID : " << task.getId() << "\n";
        cout << "Nom : " << task.getName() << "\n";
        cout << "Description : " << task.getDescription() << "\n";
        cout << "Priorité : " << priority << "\n";
        cout << "Date de début : " << task.getStartDate() << "\n";
        cout << "Date de fin : " << task.getEndDate() << "\n";
        cout << "------------------------\n";
    }
}

/**
 * @brief Display a task
 *
 * This function displays a task
 *
 * @param inputFile The input file
 * @param id The id of the task
 */
void displayTask(ofstream &inputFile, int id)
{
    json taskJson;
    while (inputFile >> taskJson)
    {
        Task task = JSONHelper::jsonToTask(taskJson);
        if (task.getId() == id)
        {
            string priority = task.getPriority() == Priority::HIGH ? "HIGH" : (task.getPriority() == Priority::MEDIUM ? "MEDIUM" : "LOW");
            cout << "ID : " << task.getId() << "\n";
            cout << "Nom : " << task.getName() << "\n";
            cout << "Description : " << task.getDescription() << "\n";
            cout << "Priorité : " << priority << "\n";
            cout << "Date de début : " << task.getStartDate() << "\n";
            cout << "Date de fin : " << task.getEndDate() << "\n";
            cout << "------------------------\n";
        }
    }
}