#ifndef TASK_H
#define TASK_H

using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <fstream>


enum class Priority{LOW,MEDIUM,HIGH};

class Task {

    private:
        int id;
        string name;
        string description;
        string priority;
        string startDate;
        string endDate;

    public:
        Task(int id, string name, string description, Priority priority, string startDate, string endDate);
        int getId();
        string getName();
        string getDescription();
        string getPriority();
        string getStartDate();
        string getEndDate();
};

#endif
