#include "../../includes/todo.h"
#include "../../includes/task.h"
#include "../../includes/sort.h"

using namespace std;

/**
 * @brief Display the list of tasks
 *
 * This function displays the list of tasks and
 * sorts according to the option the user has set
 *
 * @param ofstream The input file
 * @param typeSort The type of sorting
 */
void displayTasks(ifstream &file, string typeSort)
{

    json taskJson;
    vector<Task> tasks;
    json data = json::parse(file);
    for(json& jsonTask : data)
    {
        Task task = JSONHelper::jsonToTask(jsonTask);
        tasks.push_back(task);
    }
    if(typeSort == "id") {
        sortTasksById(tasks);
    } else if (typeSort == "name") {
        sortTasksByName(tasks);
    } else if (typeSort == "desc") {
        sortTasksByDescription(tasks);
    } else if (typeSort == "prio") {
        sortTasksByPriority(tasks);
    } else if (typeSort == "dc") {
        sortTasksByStartDate(tasks);
    } else if (typeSort == "df") {
        sortTasksByEndDate(tasks);
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
/*void displayTask(ofstream &inputFile, int id)
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
}*/