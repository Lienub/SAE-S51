#include "../../includes/task.h"

Task::Task(int id, string name, string description, Priority priority, string startDate, string endDate){
    this->id = id;
    this->name = name;
    this->description = description;
    this->priority = priority;
    this->startDate = startDate;
    this->endDate = endDate;
}

int Task::getId() {
    return id;
}

string Task::getName() {
    return name;
}

string Task::getDescription() {
    return description;
}

Priority Task::getPriority() {
    return priority;
}

string Task::getStartDate() {
    return startDate;
}

string Task::getEndDate() {
    return endDate;
}
