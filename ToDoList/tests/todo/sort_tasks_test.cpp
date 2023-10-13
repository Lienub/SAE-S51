#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "../catch2/catch.hpp"
#include "../../includes/sort.h"
#include "../../includes/task.h"

TEST_CASE("Sorting tasks by ID", "[sortTasksById]") {
    Task task1(1, "Task 1", "Description 1", Priority::HIGH, "2022-01-01", "2022-01-02");
    Task task2(2, "Task 2", "Description 2", Priority::LOW, "2022-01-01", "2022-01-02");
    Task task3(3, "Task 3", "Description 3", Priority::MEDIUM, "2022-01-01", "2022-01-02");

    std::vector<Task> tasks = {task2, task3, task1};

    sortTasksById(tasks);

    REQUIRE(tasks[0].getId() == 1);
    REQUIRE(tasks[1].getId() == 2);
    REQUIRE(tasks[2].getId() == 3);
}

TEST_CASE("Sorting tasks by name", "[sortTasksByName]") {
    Task task1(1, "Task B", "Description 1", Priority::HIGH, "2022-01-01", "2022-01-02");
    Task task2(2, "Task C", "Description 2", Priority::LOW, "2022-01-01", "2022-01-02");
    Task task3(3, "Task A", "Description 3", Priority::MEDIUM, "2022-01-01", "2022-01-02");

    std::vector<Task> tasks = {task2, task3, task1};

    sortTasksByName(tasks);

    REQUIRE(tasks[0].getName() == "Task A");
    REQUIRE(tasks[1].getName() == "Task B");
    REQUIRE(tasks[2].getName() == "Task C");
}

TEST_CASE("Sorting tasks by description", "[sortTasksByDescription]") {
    Task task1(1, "Task 1", "Description C", Priority::HIGH, "2022-01-01", "2022-01-02");
    Task task2(2, "Task 2", "Description A", Priority::LOW, "2022-01-01", "2022-01-02");
    Task task3(3, "Task 3", "Description B", Priority::MEDIUM, "2022-01-01", "2022-01-02");

    std::vector<Task> tasks = {task2, task3, task1};

    sortTasksByDescription(tasks);

    REQUIRE(tasks[0].getDescription() == "Description A");
    REQUIRE(tasks[1].getDescription() == "Description B");
    REQUIRE(tasks[2].getDescription() == "Description C");
}

TEST_CASE("Sorting tasks by priority", "[sortTasksByPriority]") {
    Task task1(1, "Task 1", "Description 1", Priority::LOW, "2022-01-01", "2022-01-02");
    Task task2(2, "Task 2", "Description 2", Priority::MEDIUM, "2022-01-01", "2022-01-02");
    Task task3(3, "Task 3", "Description 3", Priority::HIGH, "2022-01-01", "2022-01-02");

    std::vector<Task> tasks = {task2, task3, task1};

    sortTasksByPriority(tasks);

    REQUIRE(tasks[0].getPriority() == "HIGH");
    REQUIRE(tasks[1].getPriority() == "MEDIUM");
    REQUIRE(tasks[2].getPriority() == "LOW");
}



TEST_CASE("Sorting tasks by start date", "[sortTasksByStartDate]") {
    Task task1(1, "Task 1", "Description 1", Priority::HIGH, "2022-01-03", "2022-01-04");
    Task task2(2, "Task 2", "Description 2", Priority::LOW, "2022-01-01", "2022-01-02");
    Task task3(3, "Task 3", "Description 3", Priority::MEDIUM, "2022-01-02", "2022-01-03");

    std::vector<Task> tasks = {task2, task3, task1};

    sortTasksByStartDate(tasks);

    REQUIRE(tasks[0].getStartDate() == "2022-01-01");
    REQUIRE(tasks[1].getStartDate() == "2022-01-02");
    REQUIRE(tasks[2].getStartDate() == "2022-01-03");
}


TEST_CASE("Sorting tasks by end date", "[sortTasksByEndDate]") {
    Task task1(1, "Task 1", "Description 1", Priority::HIGH, "2022-01-03", "2022-01-04");
    Task task2(2, "Task 2", "Description 2", Priority::LOW, "2022-01-01", "2022-01-03");
    Task task3(3, "Task 3", "Description 3", Priority::MEDIUM, "2022-01-02", "2022-01-02");

    std::vector<Task> tasks = {task2, task3, task1};

    sortTasksByEndDate(tasks);

    REQUIRE(tasks[0].getEndDate() == "2022-01-02");
    REQUIRE(tasks[1].getEndDate() == "2022-01-03");
    REQUIRE(tasks[2].getEndDate() == "2022-01-04");
}