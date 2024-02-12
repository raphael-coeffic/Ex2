CC = gcc 
FLAGS = -Wall
OBJECTS_FIRST_MAIN = my_graph.o
OBJECTS_SECOND_MAIN = my_Knapsack.o

all: my_graph my_Knapsack

my_graph: $(OBJECTS_FIRST_MAIN) my_mat.o
	$(CC) $(FLAGS) $(OBJECTS_FIRST_MAIN) my_mat.o -o my_graph

my_Knapsack: $(OBJECTS_SECOND_MAIN)
	$(CC) $(FLAGS) $(OBJECTS_SECOND_MAIN) -o my_Knapsack

my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c

my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_mat.o: my_mat.c my_mat.h
	$(CC)$(FLAGS) -c my_mat.c 	

.PHONY: clean

clean:
	rm -f *.o my_graph my_Knapsack
