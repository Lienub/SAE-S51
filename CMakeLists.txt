cmake_minimum_required(VERSION 3.12.2)

project (todolist)

add_library(files STATIC ToDoList/src/utils/files.cpp)
add_library(sort STATIC ToDoList/src/utils/sort.cpp)
add_library(task STATIC ToDoList/src/task/task.cpp)
add_library(create_task STATIC ToDoList/src/options/create_task.cpp)
add_library(delete_task STATIC ToDoList/src/options/delete_task.cpp)
add_library(modify_task STATIC ToDoList/src/options/modify_task.cpp)
add_library(tasks_display STATIC ToDoList/src/options/tasks_display.cpp)
add_library(json_helper STATIC ToDoList/src/helper/json_helper.cpp)

add_executable(todolistapp ToDoList/src/main.cpp)

target_include_directories(todolistapp
    PUBLIC "{CMAKE_CURRENT_SOURCE_DIR}/includes"
    PUBLIC "{CMAKE_CURRENT_SOURCE_DIR}/data"
    PUBLIC "{CMAKE_CURRENT_SOURCE_DIR}/src"
)


target_link_libraries(files task)
target_link_libraries(sort task)
target_link_libraries(create_task task json_helper sort)
target_link_libraries(delete_task json_helper task)
target_link_libraries(modify_task json_helper task)
target_link_libraries(tasks_display json_helper task)
target_link_libraries(todolistapp task files sort create_task delete_task modify_task tasks_display)

install(TARGETS todolistapp
    COMPONENT linapp
    RUNTIME DESTINATION "/ToDoList/home/"
    LIBRARY DESTINATION "/ToDoList/home/"
    DESTINATION "/ToDoList/home/"
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK")
INCLUDE(CPack)