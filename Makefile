CC = gcc
AR = ar
CFLAGS = -g -Wall
OBJECTS_MAIN = main.c graph.h
OBJECTS_NODES = nodes.c 
OBJECTS_EDGES = edges.c
O_FILES= main.o nodes.o edges.o
MAIN_PROG = graph
ALL_OBJFILES= main.o nodes.o edges.o graph

all : $(ALL_OBJFILES) 



$(MAIN_PROG) : $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -o $(MAIN_PROG)



main.o : $(OBJECTS_MAIN)
	$(CC) $(CFLAGS) -c main.c


nodes.o : $(OBJECTS_NODES)
	$(CC) $(CFLAGS) -c nodes.c

edges.o : $(OBJECTS_EDGES)
	$(CC) $(CFLAGS) -c edges.c




.PHONY: clean all

clean:
	rm -f *.o $(MAIN_PROG)