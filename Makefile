CC=gcc-9
CFLAGS=-Wall -Wextra
LIBS=-lm
LDFLAGS=

prog: main.o functions.o
	$(CC) functions.o main.o $(LIBS) -o prog

main.o: main.c functions.h
	$(CC) -c $(CFLAGS) main.c


functions.o: functions.c functions.h
	$(CC) -c $(CFLAGS) functions.c

clear:
	rm -rf *.o prog