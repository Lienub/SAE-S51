#include "task.h"
#include "json_helper.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

// Define the createTask function
Task createTask(ofstream& outputFile) {

    // Prompt the user for task details
    int newId;
    string newName, newDescription, newStartDate, newEndDate;
    Priority newPriority;

    // Loop until valid input is provided for ID
    while (true) {
        cout << "ID de la tâche : ";
        cin >> newId;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ID invalide. Veuillez entrer un nombre entier.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

   // Loop until valid input is provided for Name (up to 64 characters)
    while (true) {
        cout << "Nom de la tâche (max 64 caractères) : ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, newName);

        if (newName.length() > 64) {
            cout << "Le nom de la tâche ne peut pas dépasser 64 caractères. Veuillez réessayer.\n";
        } else if (newName.empty()) {
            cout << "Le nom de la tâche ne peut pas être vide. Veuillez réessayer.\n";
        } else {
            break;
        }
    }

    // Loop until valid input is provided for Description
    while (true) {
        cout << "Description de la tâche : ";
        getline(cin, newDescription);

        if (newDescription.empty()) {
            cout << "La description ne peut pas être vide. Veuillez réessayer.\n";
        } else {
            break;
        }
    }

    // Loop until valid input is provided for Priority
    while (true) {
        cout << "Priorité (LOW, MEDIUM, HIGH) : ";
        string priorityStr;
        cin >> priorityStr;

        if (priorityStr == "LOW") {
            newPriority = Priority::LOW;
            break;
        } else if (priorityStr == "MEDIUM") {
            newPriority = Priority::MEDIUM;
            break;
        } else if (priorityStr == "HIGH") {
            newPriority = Priority::HIGH;
            break;
        } else {
            cout << "Priorité invalide. Veuillez choisir parmi LOW, MEDIUM, HIGH.\n";
        }
    }

    // Loop until valid input is provided for Start Date
    while (true) {
        cout << "Date de début de la tâche : ";
        cin >> newStartDate;

        if (newStartDate.empty()) {
            newStartDate = "none";
        }

        break;
    }

    // Loop until valid input is provided for End Date
    while (true) {
        cout << "Date de fin de la tâche : ";
        cin >> newEndDate;

        if (newEndDate.empty()) {
            newEndDate = "none";
        }

        break;
    }

    // Create a new Task object
    Task newTask(newId, newName, newDescription, newPriority, newStartDate, newEndDate);

    // Convert the task to JSON using the JSON helper module
    json taskJson = JSONHelper::taskToJson(newTask);

    // Write the JSON data to the output file
    outputFile << taskJson.dump(4) << endl;

    cout << "Tâche créée avec succès.\n";

    return newTask; // Return the new task
}
