cmake_minimum_required(VERSION 3.10)

project(TEST_TASK)

set(TEST_SOURCES 
    tests/task/task_content_test.cpp
    src/task/task.cpp
)
add_executable(TEST_TASK ${TEST_SOURCES})

target_include_directories(TEST_TASK PRIVATE src/task)

enable_testing()

add_test(NAME Task_Content COMMAND TEST_TASK)