#include "../../includes/task.h"
#include "../../includes/json_helper.h"
#include "../../includes/sort.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @brief Create a new task and write it to the output file.
 *
 * This function prompts the user to input details for a new task, validates the input,
 * creates a new Task object, converts it to JSON format using the JSON helper module,
 * and writes the JSON data to the specified output file.
 *
 * @param outputFile The output file to write the new task to.
 * @return The new task.
 */
Task createTask(ifstream &inputFile, ofstream &outputFile)
{

    // Prompt the user for task details
    int newId;
    string newName, newDescription, newStartDate, newEndDate, newPriority;

    json data = json::parse(inputFile);
    vector<Task> tasks;
    for (json &jsonTask : data)
    {
        Task task = JSONHelper::jsonToTask(jsonTask);
        tasks.push_back(task);
    }
    if(!tasks.empty()) {
        sortTasksById(tasks);
        newId = tasks.back().getId() + 1;
    } else {
        newId = 1;
    }

    // Loop until valid input is provided for Name (up to 64 characters)
    while (true)
    {
        cout << "Nom de la tâche (max 64 caractères) : ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, newName);

        if (newName.length() > 64)
        {
            cout << "Le nom de la tâche ne peut pas dépasser 64 caractères. Veuillez réessayer.\n";
        }
        else if (newName.empty())
        {
            cout << "Le nom de la tâche ne peut pas être vide. Veuillez réessayer.\n";
        }
        else
        {
            break;
        }
    }

    // Loop until valid input is provided for Description
    while (true)
    {
        cout << "Description de la tâche : ";
        getline(cin, newDescription);

        if (newDescription.empty())
        {
            cout << "La description ne peut pas être vide. Veuillez réessayer.\n";
        }
        else
        {
            break;
        }
    }

    // Loop until valid input is provided for Priority
    while (true)
    {
        cout << "Priorité (LOW, MEDIUM, HIGH) : ";
        cin >> newPriority;

        if (newPriority != "LOW" && newPriority != "MEDIUM" && newPriority != "HIGH")
        {
            cout << "La priorité doit être LOW, MEDIUM ou HIGH. Veuillez réessayer.\n";
        }
        else
        {
            break;
        }
    }

    // Loop until valid input is provided for Start Date
    while (true)
    {
        cout << "Date de début de la tâche : ";
        cin >> newStartDate;

        if (newStartDate.empty())
        {
            newStartDate = "none";
        }

        break;
    }

    // Loop until valid input is provided for End Date
    while (true)
    {
        cout << "Date de fin de la tâche : ";
        cin >> newEndDate;

        if (newEndDate.empty())
        {
            newEndDate = "none";
        }

        break;
    }

    Task newTask(newId, newName, newDescription, (newPriority == "HIGH") ? Priority::HIGH : (newPriority == "MEDIUM") ? Priority::MEDIUM
                                                                                                                      : Priority::LOW,
                 newStartDate, newEndDate);
    tasks.push_back(newTask);

    json tasksJsonArray;
    for (Task &task : tasks)
    {
        tasksJsonArray.push_back(JSONHelper::taskToJson(task));
    }

    outputFile << tasksJsonArray.dump(4);

    inputFile.close();
    outputFile.close();

    cout << "Tâche créée avec succès.\n";

    return newTask;
}
