#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../../includes/task.h"
#include <sstream>
#include <fstream>

TEST_CASE("Test Task Body", "[task]")
{
    Task task(123, "Faire les courses", "Acheter des fruits", Priority::MEDIUM, "2023-10-01", "2023-10-02");

    REQUIRE(task.getId() == 123);
    REQUIRE(task.getName() == "Faire les courses");
    REQUIRE(task.getDescription() == "Acheter des fruits");
    REQUIRE(task.getPriority() == "MEDIUM");
    REQUIRE(task.getStartDate() == "2023-10-01");
    REQUIRE(task.getEndDate() == "2023-10-02");
}