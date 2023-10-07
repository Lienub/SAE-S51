#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../../includes/files.h"

TEST_CASE("Testing loadFilename function", "[loadFilename]") {
    SECTION("Test with existing file in load files") {
        string filenameLoadFiles = "../data/test_load_files.txt";
        string type = "in";
        string expectedFilename = "../data/input_tasks_test.json";
        ofstream testFile(filenameLoadFiles);
        testFile << type + "|" + expectedFilename << endl;
        testFile.close();

        string result = loadFilename(filenameLoadFiles, type);
        REQUIRE(result == expectedFilename);
    }

    SECTION("Test with non-existing file in load files") {
        string filenameLoadFiles = "../data/output_tasks_test.json";
        string type = "out";

        string result = loadFilename(filenameLoadFiles, type);
        REQUIRE(result == "");
    }
}

TEST_CASE("Testing saveFilenameLoaded function", "[saveFilenameLoaded]") {
    SECTION("Test with existing file in load files") {
        string loadFile = "../data/test_load_files.txt";
        string type = "out";
        string expectedFilename = "../data/output_tasks_test.json";

        ofstream testFile(loadFile);
        testFile << type + "|" + expectedFilename << endl;
        testFile.close();

        int result = saveFilenameLoaded(expectedFilename, loadFile, type);
        REQUIRE(result == 1);

        ifstream inputFile(loadFile);
        string line;
        getline(inputFile, line);
        inputFile.close();
        REQUIRE(line == type + "|" + expectedFilename);
    }

    SECTION("Test with non-existing file in load files") {
        string loadFile = "../data/test_load_files.txt";
        string type = "out";
        string expectedFilename = "../data/not_exist_tasks_test.json";

        int result = saveFilenameLoaded(loadFile, expectedFilename, type);
        REQUIRE(result == 0);
    }
}