CC = gcc
AR = ar
CFLAGS = -g -Wall
OBJECTS_MAIN = main.c
OBJECTS_NODES = nodes.c nodes.h
OBJECTS_EDGES = edges.c edges.h
OBJECTS_ALGO = algo.c algo.h
O_FILES= main.o nodes.o edges.o algo.o
MAIN_PROG = graph
ALL_OBJFILES= main.o nodes.o edges.o algo.o graph

# ALL_OBJFILES = my_mat.o main.o my_mat.a connections
# OBJECTS_MAIN = main.c my_mat.h
# MY_MAT_OBJECTS = my_mat.c my_mat.h
# CONNECTIONS = connections

# all : $(ALL_OBJFILES) 

# $(CONNECTIONS) : my_mat.a main.o
# 	$(CC) $(CFLAGS) main.o my_mat.a -o $(CONNECTIONS)

# mymat: my_mat.a

# my_mat.a: my_mat.o
# 	$(AR) -rcs my_mat.a my_mat.o

# main.o : $(OBJECTS_MAIN)
# 	$(CC) $(CFLAGS) -c main.c

# my_mat.o : $(MY_MAT_OBJECTS)
# 	$(CC) $(CFLAGS) -c my_mat.c

all : $(ALL_OBJFILES) 



$(MAIN_PROG) : $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -o $(MAIN_PROG)



main.o : $(OBJECTS_MAIN)
	$(CC) $(CFLAGS) -c main.c


nodes.o : $(OBJECTS_NODES)
	$(CC) $(CFLAGS) -c nodes.c

edges.o : $(OBJECTS_EDGES)
	$(CC) $(CFLAGS) -c edges.c

algo.o : $(OBJECTS_ALGO)
	$(CC) $(CFLAGS) -c algo.c




.PHONY: clean all

clean:
	rm -f *.o $(MAIN_PROG)