#include "json_helper.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace JSONHelper {

    json taskToJson(const Task& task) {
        json taskJson;
        taskJson["id"] = task.getId();
        taskJson["name"] = task.getName();
        taskJson["description"] = task.getDescription();
        taskJson["priority"] = static_cast<int>(task.getPriority());
        taskJson["start_date"] = task.getStartDate();
        taskJson["end_date"] = task.getEndDate();
        return taskJson;
    }

}