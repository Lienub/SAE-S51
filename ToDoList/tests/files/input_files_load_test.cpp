#include "../../includes/files.h"
#include <cassert>

string loadFile = "../data/load_files.txt";
string inputLoadFile = "../data/input_load_file.json";

int main() {
    saveFilenameLoaded(inputLoadFile, loadFile, "in");
    string filename = loadFilename(loadFile, "in");
    assert(filename == inputLoadFile);
    return 0;
}