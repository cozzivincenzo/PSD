main: main.o libro.o functions.o
	gcc main.o libro.o functions.o -lm -o main
	
main.o: main.c
	gcc -c main.c

libro.o: libro.c
	gcc -c libro.c

functions.o: functions.c
	gcc -c functions.c

	