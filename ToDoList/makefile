CC = g++
CFLAGS = -std=c++17 -Wall
SRCDIR = src
INCDIR = include
BUILDDIR = build

all: todo

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)
	
todo: $(BUILDDIR)/main.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(BUILDDIR)/*.o todo

