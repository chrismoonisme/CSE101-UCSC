#Christopher Moon
#ckmoon
#pa1
#------------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 1
#
#------------------------------------------------------------------------------
all : Lex ListTest

Lex : Lex.o List.o
	gcc -std=c17 -Wall -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -std=c17 -Wall -c Lex.c

ListTest: ListTest.o List.o
	gcc -std=c17 -Wall -o ListTest ListTest.o List.o

ListTest.o : ListTest.c List.h
	gcc -std=c17 -Wall -c ListTest.c

List.o : List.c List.h
	gcc -std=c17 -Wall -c List.c

clean :
	rm -f Lex ListTest Lex.o ListTest.o List.o

checkTest : 
	valgrind --leak-check=full ListTest

#checkLex :
	#valgrind --leak-check=full Lex in3 blah3

