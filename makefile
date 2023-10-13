CC = g++
CFLAGS = -std=c++17 -Wall
SRCDIR = ToDoList/src
INCDIR = ToDoList/includes
BUILDDIR = ToDoList/build
TESTSDIR = ToDoList/tests

all: todo
	cd $(BUILDDIR) && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ../tests && make

$(BUILDDIR)/task.o: $(SRCDIR)/task/task.cpp $(INCDIR)/task.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/tasks_display.o: $(SRCDIR)/options/tasks_display.cpp $(INCDIR)/sort.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/files.o: $(SRCDIR)/utils/files.cpp $(INCDIR)/files.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/delete_task.o: $(SRCDIR)/options/delete_task.cpp $(INCDIR)/todo.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/modify_task.o: $(SRCDIR)/options/modify_task.cpp $(INCDIR)/todo.h $(INCDIR)/nlohmann/json.hpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/create_task.o: $(SRCDIR)/options/create_task.cpp $(INCDIR)/todo.h $(INCDIR)/nlohmann/json.hpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/json_helper.o: $(SRCDIR)/helper/json_helper.cpp $(INCDIR)/json_helper.h $(INCDIR)/nlohmann/json.hpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/sort.o: $(SRCDIR)/utils/sort.cpp $(INCDIR)/sort.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
	
todo: $(BUILDDIR)/main.o $(BUILDDIR)/task.o $(BUILDDIR)/tasks_display.o $(BUILDDIR)/sort.o $(BUILDDIR)/json_helper.o $(BUILDDIR)/delete_task.o $(BUILDDIR)/files.o $(BUILDDIR)/create_task.o $(BUILDDIR)/modify_task.o
	$(CC) $(CFLAGS) $^ -o $@

test:
	cd ToDoList/tests/bin && ./task_content_test --success > ../../../tests_logs/task_content_test.log
	cd ToDoList/tests/bin && ./sort_tasks_test --success > ../../../tests_logs/sort_tasks_test.log
	cd ToDoList/tests/bin && ./delete_task_test --success > ../../../tests_logs/delete_task_test.log
	cd ToDoList/tests/bin && ./load_files_test --success > ../../../tests_logs/load_files_test.log

documentation:
	doxygen Doxyfile

check-code:
	- cppcheck --enable=all . > checkcpp-reports/checkcpp-report.log
	- cppcheck --enable=all --xml --xml-version=2 . 2> checkcpp-reports/checkcpp-errors-report.xml || true

clean:
	rm -f $(BUILDDIR)/*.o todo
	rm -rf CMakeFiles/
	rm -rf $(BUILDDIR)/*
	rm -f tests_logs/*.log
	rm -rf $(TESTSDIR)/bin/*
