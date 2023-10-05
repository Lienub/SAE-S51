#ifndef JSON_HELPER_H
#define JSON_HELPER_H

#include "task.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace JSONHelper {

    json taskToJson(const Task& task);
    Task jsonToTask(json taskJson);

}

#endif