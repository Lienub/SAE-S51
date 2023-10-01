CC = g++
CFLAGS = -std=c++17 -Wall
SRCDIR = src
INCDIR = includes
BUILDDIR = build

all: todo
	cd $(BUILDDIR) && cmake .. && make

$(BUILDDIR)/task.o: $(SRCDIR)/task/task.cpp $(INCDIR)/task.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
	
todo: $(BUILDDIR)/main.o $(BUILDDIR)/task.o
	$(CC) $(CFLAGS) $^ -o $@

test:
	cd $(BUILDDIR) && ctest > ../tests/logs/tests.log

clean:
	rm -f $(BUILDDIR)/*.o todo
	rm -rf CMakeFiles/
	rm -rf $(BUILDDIR)/*
	rm -f tests/logs/*.log


