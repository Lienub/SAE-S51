#include "../includes/task.h"

Task::Task(int id, string name, string description, Priority priority, string creationDate, string endDate){
    this->id = id;
    this->name = name;
    this->description = description;
    this->priority = priority;
    this->creationDate = creationDate;
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

string Task::getCreationDate() {
    return creationDate;
}

string Task::getEndDate() {
    return endDate;
}
