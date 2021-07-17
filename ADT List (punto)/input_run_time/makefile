main: main.o item.o list.o functions.o
	gcc main.o item.o list.o functions.o -lm -o main 
	
functions.o: functions.c
	gcc -c functions.c

item.o: item.c
	gcc -c item.c
	
list.o: list.c 
	gcc -c list.c
	
main.o: main.c 
	gcc -c main.c	 