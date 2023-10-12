#include "../../includes/task.h"
#include "../../includes/json_helper.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>

using namespace std;

void modifyTask(ifstream &inputFile, ofstream &outputFile, int taskId)
{
    json data = json::parse(inputFile);
    vector<Task> tasks;
    for (json &jsonTask : data)
    {
        Task task = JSONHelper::jsonToTask(jsonTask);
        tasks.push_back(task);
    }

    for (Task &task : tasks)
    {
        if (task.getId() == taskId)
        {
            Task currentTask = task;
            string newName = "", newDescription = "", priorityStr = "", newStartDate = "", newEndDate = "";
            while (true)
            {
                cout << "1 - Nom de la tache\n"
                     << "2 - Description de la tache\n"
                     << "3 - Priorité\n"
                     << "4 - Date de début de la tâche\n"
                     << "5 - Date de fin de la tâche\n"
                     << "6 - Sortir\n";
                cout << "Choisissez une option : ";
                int choice;
                cin >> choice;

                if (choice == 1)
                {
                    cout << "Nom de la tâche (max 64 caractères) : ";
                    cin.ignore();
                    getline(cin, newName);
                    if (newName.length() > 64)
                    {
                        cout << "Le nom de la tâche ne peut pas dépasser 64 caractères. Veuillez réessayer.\n";
                    }
                    else if (newName.empty())
                    {
                        cout << "Le nom de la tâche ne peut pas être vide. Veuillez réessayer.\n";
                    }
                }
                else if (choice == 2)
                {
                    cout << "Description de la tâche : ";
                    cin.ignore();
                    getline(cin, newDescription);
                }
                else if (choice == 3)
                {
                    cout << "Priorité (LOW, MEDIUM, HIGH) : ";
                    cin.ignore();
                    getline(cin, priorityStr);
                }
                else if (choice == 4)
                {
                    cout << "Date de début de la tâche : ";
                    cin.ignore();
                    getline(cin, newStartDate);

                    if (newStartDate.empty())
                    {
                        newStartDate = "none";
                    }
                }
                else if (choice == 5)
                {
                    cout << "Date de fin de la tâche : ";
                    cin.ignore();
                    getline(cin, newEndDate);

                    if (newEndDate.empty())
                    {
                        newEndDate = "none";
                    }
                }
                else
                {
                    break;
                }
            }
            string newPriority = "";
            if (newName == "")
            {
                cout << "Aucune modification effectuée.\n";
                newName = currentTask.getName();
                cout << "test\n";
            }
            if (newDescription == "")
            {
                newDescription = currentTask.getDescription();
            }
            if (priorityStr == "")
            {
                newPriority = currentTask.getPriority();
            }
            if (newStartDate == "")
            {
                newStartDate = currentTask.getStartDate();
            }
            if (newEndDate == "")
            {
                newEndDate = currentTask.getEndDate();
            }

            Task newTask(taskId, newName, newDescription, (newPriority == "HIGH") ? Priority::HIGH : ((newPriority == "MEDIUM") ? Priority::MEDIUM : Priority::LOW) , newStartDate, newEndDate);
            json tasksJsonArray;
            for (Task &task : tasks)
            {
                if (task.getId() != taskId)
                {
                    tasksJsonArray.push_back(JSONHelper::taskToJson(task));
                }
            }
            tasksJsonArray.push_back(JSONHelper::taskToJson(newTask));

            outputFile << tasksJsonArray.dump(4);

            cout << "Tâche modifiée avec succès.\n";

            inputFile.close();
            outputFile.close();
        }
    }
    inputFile.close();
    outputFile.close();
}