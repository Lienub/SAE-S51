#include "../../includes/files.h"
#include <cassert>

string loadFile = "../data/load_files.txt";
string outputFile = "../data/output_load_file.json";

int main() {
    saveFilenameLoaded(outputFile, loadFile, "out");
    string filename = loadFilename(loadFile, "out");
    assert(filename == outputFile);
    return 0;
}