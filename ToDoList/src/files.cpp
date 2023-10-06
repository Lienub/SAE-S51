#include <iostream>
#include <fstream>
#include <string>
#include "../includes/task.h"
#include "../includes/files.h"

string loadFilename(string filenameLoadFiles, string type)
{
    fstream fileLoad(filenameLoadFiles, fstream::in);
    if (!fileLoad.is_open())
    {
        cout << "Erreur lors de la lecture du fichier\n";
        return "";
    }
    string line;
    string filename = "";
    while (getline(fileLoad, line))
    {
        if (line.substr(0, line.find('|')) == type)
        {
            fileLoad.close();
            filename = line.substr(line.find('|') + 1, line.length());
        }
    }
    fileLoad.close();
    return filename;
}

int saveFilenameLoaded(string loadFile, string filename, string type)
{
    fstream fstreamFile(filename, fstream::in);
    if (!fstreamFile.is_open())
    {
        cout << "Votre fichier n'existe pas\n";
        fstreamFile.close();
        return 1;
    }
    else
    {
        ofstream outputLoadedFile("load_files_temp.txt");
        string line;
        while (getline(fstreamFile, line))
        {
            if (line.substr(0, line.find('|')) != type)
            {
                outputLoadedFile << line << "\n";
            }
        }
        outputLoadedFile << type + "|" + loadFile << "\n";
        outputLoadedFile.close();
        fstreamFile.close();
        remove(filename.c_str());
        rename("load_files_temp.txt", filename.c_str());
        fstreamFile.close();
    }
    return 0;
}
