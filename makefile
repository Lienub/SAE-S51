CC = g++
CFLAGS = -std=c++17 -Wall
SRCDIR = ToDoList/src
INCDIR = ToDoList/includes
BUILDDIR = ToDoList/build
TESTSDIR = ToDoList/tests

all: todo
	cd $(BUILDDIR) && cmake ../tests && make

$(BUILDDIR)/task.o: $(SRCDIR)/task/task.cpp $(INCDIR)/task.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/tasks_display.o: $(SRCDIR)/options/tasks_display.cpp $(INCDIR)/sort.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/json_helper.o: $(SRCDIR)/helper/json_helper.cpp $(INCDIR)/json_helper.h $(INCDIR)/nlohmann/json.hpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/sort.o: $(SRCDIR)/utils/sort.cpp $(INCDIR)/sort.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
	
todo: $(BUILDDIR)/main.o $(BUILDDIR)/task.o $(BUILDDIR)/tasks_display.o $(BUILDDIR)/sort.o $(BUILDDIR)/json_helper.o
	$(CC) $(CFLAGS) $^ -o $@

test:
	cd ToDoList/tests/bin && ./sort_tasks_test --success > ../../../tests_logs/sort_tasks_test.log

clean:
	rm -f $(BUILDDIR)/*.o todo
	rm -rf CMakeFiles/
	rm -rf $(BUILDDIR)/*
	rm -f tests_logs/*.log
	rm -rf $(TESTSDIR)/bin/*