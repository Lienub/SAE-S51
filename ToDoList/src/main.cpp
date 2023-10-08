#include <iostream>
#include <string>
#include "../includes/task.h"
#include "../includes/todo.h"
#include "../includes/files.h"

using namespace std;

string loadFilenames = "ToDoList/data/load_files.txt";

void help()
{
    cout << "Commandes:\n";
    cout << "./todo <option>\n\n";
    cout << "OPTIONS:\n";
    cout << "\t-c (Démarre la création d'une nouvelle tache)\n";
    cout << "\t-r (Affiche la liste des taches)\n";
    cout << "\t\t-o <name,desc, dc, df, prio, id> (Trier les taches)\n";
    cout << "\t-r <ID> (Affiche la tache avec l'ID donnée)\n";
    cout << "\t-u <ID> (Modifier la tache avec l'ID donnée)\n";
    cout << "\t-d <ID> (Supprimer la tache avec l'ID donnée)\n";
    cout << "\t-l <file> (Rensigner le fichier qu'on veut charger, consulter ou modifier)\n";
    cout << "\t-s <file> (Renseigner le fichier sur lequel sauvegarder la liste des tâches après modifications)\n";
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        help();
        return 0;
    }
    if (string(argv[1]) == "-c")
    {
        cout << "Creation d'une nouvelle tache\n";
    
        string filename = loadFilename(loadFilenames, "in");
        ifstream inptuFilename(filename);
        filename = loadFilename(loadFilenames, "out");
        ofstream outputFilename(filename);
        json json_data = json::parse(inptuFilename);
        outputFilename << json_data.dump(4);
        outputFilename.close();
        inptuFilename.close();

        filename = loadFilename(loadFilenames, "in");
        ifstream inputFile(filename);
        filename = loadFilename(loadFilenames, "out");
        ofstream outputFile(filename);
        createTask(inputFile, outputFile);
    }
    else if (string(argv[1]) == "-r")
    {
        if (argc == 2)
        {
            cout << "\n=================================================\n";
            cout << "========== Affiche la liste des taches"
                 << " ==========\n";
            cout << "=================================================\n\n";
            string filename = loadFilename(loadFilenames, "in");
            ifstream f(filename);
            displayTasks(f, "");
        }
        else
        {
            if (argc == 3)
            {
                string input = argv[2];
                try
                {
                    string filename = loadFilename(loadFilenames, "in");
                    ifstream f(filename);
                    displayTask(f, stoi(argv[2]));
                }
                catch (const std::invalid_argument &e)
                {
                    cout << "\n=================================================\n";
                    cout << "========== Affiche la liste des taches"
                         << " ==========\n";
                    cout << "=================================================\n\n";
                    string filename = loadFilename(loadFilenames, "in");
                    ifstream f(filename);
                    displayTasks(f, "");
                }
            }
            else if (argc == 4)
            {
                if (strcmp(argv[2], "-o") == 0)
                {
                    cout << "\n===============================================================\n";
                    cout << "========== Affiche la liste des taches trié par " << argv[3] << " ==========\n";
                    cout << "===============================================================\n\n";
                    string filename = loadFilename(loadFilenames, "in");
                    ifstream f(filename);
                    displayTasks(f, argv[3]);
                }
            }
            else
            {
                help();
            }
        }
    }
    else if (string(argv[1]) == "-u")
    {
        cout << "Modification de la tache avec l'ID donnée\n";
        // TODO
    }
    else if (string(argv[1]) == "-d")
    {
        if (argc == 3)
        {
            string filename = loadFilename(loadFilenames, "in");
            ifstream inputFile(filename);
            json contentJson = deleteTask(inputFile, stoi(argv[2]));

            filename = loadFilename(loadFilenames, "out");
            ofstream outputFile(filename);
            outputFile << contentJson.dump(4);
            outputFile.close();
        }
        else
        {
            help();
        }
    }
    else if (string(argv[1]) == "-l")
    {
        if (argc == 3)
        {
            if (saveFilenameLoaded(argv[2], loadFilenames, "in"))
            {
                cout << "Fichier " << argv[2] << " chargé avec succès\n";
            }
            else
            {
                cout << "Erreur lors de la sauvegarde du fichier " << argv[2] << "\n";
            }
        }
        else
        {
            help();
        }
    }
    else if (string(argv[1]) == "-s")
    {
        if (argc == 3)
        {
            if (saveFilenameLoaded(argv[2], loadFilenames, "out"))
            {
                cout << "Fichier " << argv[2] << " chargé avec succès\n";
            }
            else
            {
                cout << "Erreur lors de la sauvegarde du fichier " << argv[2] << "\n";
            }
        }
        else
        {
            help();
        }
    }
    else
    {
        help();
    }

    return 0;
}