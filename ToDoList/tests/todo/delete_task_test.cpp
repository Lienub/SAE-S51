#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../../includes/json_helper.h"
#include "../../includes/task.h"
#include "../../includes/todo.h"
#include <sstream>
#include <fstream>

TEST_CASE("Delete task from JSON file", "[deleteTask]")
{
    json jsonContent = R"([
        {
            "id": 1,
            "name": "Dormir",
            "description": "dormir",
            "priority": "HIGH",
            "start_date": "2020-01-01",
            "end_date": "2020-01-02"
        },
        {
            "id": 2,
            "name": "Devoirs",
            "description": "faire le projet S51",
            "priority": "HIGH",
            "start_date": "2020-01-01",
            "end_date": "2020-01-02"
        },
        {
            "id": 3,
            "name": "Courses",
            "description": "faire les courses",
            "priority": "HIGH",
            "start_date": "2020-01-01",
            "end_date": "2020-01-02"
        }
    ])"_json;

    ofstream oFile("../data/tasks_test.json");
    oFile << jsonContent.dump(4);
    oFile.close();

    ifstream iFile("../data/tasks_test.json");
    int taskIdToDelete = 2;
    json result = deleteTask(iFile, taskIdToDelete);
    iFile.close();
    REQUIRE(result.size() == 2);
    REQUIRE(result[0]["id"] == 1);
    REQUIRE(result[1]["id"] == 3);

    REQUIRE(result[0]["name"] == "Dormir");
    REQUIRE(result[1]["name"] == "Courses");
}