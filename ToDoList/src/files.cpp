#include <iostream>
#include <fstream>
#include <string>
#include "../includes/task.h"
#include "../includes/files.h"

/**
 * @brief get loaded file based on file type
 *
 * This function allows you to retrieve the name of 
 * the file which contains spots depending on the 
 * file type
 *
 * @param filenameLoadFiles The name of the file which contains the loaded files.
 * @param type The type of file (out or in)
 * @return The name of the loaded file
 */

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

/**
 * @brief save loaded file based on file type
 *
 * This function allows you to save the name of 
 * the file which contains spots depending on the 
 * file type
 *
 * @param loadFile The name of the loaded file which is saved
 * @param filename The name of the file which contains the loaded files.
 * @param type The type of file (out or in)
 * @return 0 if the file is saved, 1 if the file does not exist
 */
 
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
