#ifndef FILES_H
#define FILES_H

using namespace std;

#include <string>
#include <iostream>

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
int saveFilenameLoaded(string loadFile, string filename, string type);

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
string loadFilename(string filenameLoadFiles, string type);

#endif