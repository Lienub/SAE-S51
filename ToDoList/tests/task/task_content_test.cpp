#include "catch2/catch.hpp"
#include "../includes/task.h"
#include <cassert>

int main() {
    Task task(123, "Faire les courses", "Acheter des fruits", Priority::MEDIUM, "2023-10-01", "2023-10-02");

    assert(task.getId() == 123);
    assert(task.getName() == "Faire les courses");
    assert(task.getDescription() == "Acheter des fruits");
    assert(task.getPriority() == Priority::MEDIUM);
    assert(task.getStartDate() == "2023-10-01");
    assert(task.getEndDate() == "2023-10-02");

    return 0;
}