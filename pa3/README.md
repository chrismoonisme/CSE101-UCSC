#PA3 README, ckmoon

#FILES:

List.c: implementation of linked list ADT

List.h: header file for list.c

Graph.c: implementation of graph ADT

Graph.h: header file for graph.c

GraphTest.c: contains tests of the Graph.c functions, especially the DFS algorithm function

FindComponents.c: takes user graph and finds the strongly connected components of the graph, using the DFS algorithm

Makefile: compiles all .c files

#NOTES

Graph.c is essentially the Graph.c file from PA2, with BFS capabilities replaced with DFS

Visit helper function for DFS takes the current time as a parameter, and returns the updated time at the end.

