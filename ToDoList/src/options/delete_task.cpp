#include "../../includes/json_helper.h"
#include "../../includes/task.h"
#include "../../includes/todo.h"

using json = nlohmann::json;

json deleteTask(ifstream &file, int id)
{
    json j = json::parse(file);
    for (auto it = j.begin(); it != j.end(); ++it)
    {
        string currentIdTask = to_string(it.value()["id"].template get<int>());
        if (strcmp(currentIdTask.c_str(), to_string(id).c_str()) == 0)
        {
            j.erase(it);
            file.close();
            break;
        }
    }
    return j;
}