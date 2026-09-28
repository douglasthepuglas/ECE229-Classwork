CFLAGS = -Wall -Wextra -std=c99

all: reverse.exe

main.o: main.c utils.h
	gcc $(CFLAGS) -c main.c -o main.o -DDEBUG

utils.o: utils.c utils.h
	gcc $(CFLAGS) -c utils.c -o utils.o -DDEBUG

reverse.exe: main.o utils.o
	gcc main.o utils.o -o reverse.exe

clean:
	rm -f reverse.exe main.o utils.o
