#include "../../includes/task.h"

Task::Task(int id, string name, string description, Priority priority, string startDate, string endDate)
{
    this->id = id;
    this->name = name;
    this->description = description;
    if (priority == Priority::HIGH)
        this->priority = "HIGH";
    else if (priority == Priority::MEDIUM)
        this->priority = "MEDIUM";
    else if (priority == Priority::LOW)
        this->priority = "LOW";
    this->startDate = startDate;
    this->endDate = endDate;
}

int Task::getId()
{
    return id;
}

string Task::getName()
{
    return name;
}

string Task::getDescription()
{
    return description;
}

string Task::getPriority()
{
    return priority;
}

string Task::getStartDate()
{
    return startDate;
}

string Task::getEndDate()
{
    return endDate;
}
