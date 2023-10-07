cmake_minimum_required(VERSION 3.10)
project(ToDoListsTests)

set(CMAKE_CXX_STANDARD 11)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch2)
include_directories(${CATCH_INCLUDE_DIR})

# Liste des fichiers source de test
set(TEST_FILES
    todo/sort_tasks_test.cpp
    todo/delete_task_test.cpp
    utils/load_files_test.cpp
)


set(SOURCE_FILES
    ../src/utils/sort.cpp
    ../src/task/task.cpp
    ../src/options/delete_task.cpp
    ../src/utils/files.cpp
)

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE} ${SOURCE_FILES})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endforeach()
