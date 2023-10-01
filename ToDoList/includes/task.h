#ifndef TASK_H
#define TASK_H

using namespace std;

#include <string>
#include <iostream>


enum class Priority{LOW,MEDIUM,HIGH};

class Task {

    private:
        int id;
        string name;
        string description;
        Priority priority;
        string creationDate;
        string endDate;

    public:
        Task(int id, string name, string description, Priority priority, string creationDate, string endDate);
        int getId();
        string getName();
        string getDescription();
        Priority getPriority();
        string getCreationDate();
        string getEndDate();
};

#endif
