#include "../../includes/json_helper.h"

using json = nlohmann::json;

namespace JSONHelper
{

    void addJsonToFile(json taskJson) {
        std::ofstream file("../../data/tasks.json");

        file << taskJson;
    }

    json taskToJson(const Task &task)
    {
        json taskJson;
        taskJson["id"] = task.getId();
        taskJson["name"] = task.getName();
        taskJson["description"] = task.getDescription();
        taskJson["priority"] = static_cast<int>(task.getPriority());
        taskJson["start_date"] = task.getStartDate();
        taskJson["end_date"] = task.getEndDate();
        return taskJson;
    }

    Task jsonToTask(json taskJson)
    {
        int id = taskJson["id"].template get<int>();
        Priority priority;
        if (taskJson["priority"] == "LOW")
        {
            priority = Priority::LOW;
        }
        else if (taskJson["priority"] == "MEDIUM")
        {
            priority = Priority::MEDIUM;
        }
        else if (taskJson["priority"] == "HIGH")
        {
            priority = Priority::HIGH;
        }
        Task task = Task(id, taskJson["name"], taskJson["description"], priority, taskJson["start_date"], taskJson["end_date"]);
        return task;
    }

}