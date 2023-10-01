CC = g++
CFLAGS = -std=c++17 -Wall
SRCDIR = src
INCDIR = includes
BUILDDIR = build

all: todo

$(BUILDDIR)/task.o: $(SRCDIR)/task/task.cpp $(INCDIR)/task.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
	
todo: $(BUILDDIR)/main.o $(BUILDDIR)/task.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(BUILDDIR)/*.o todo

