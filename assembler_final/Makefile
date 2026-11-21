CC     = gcc
CFLAGS = -Wall -Wextra -std=c99

assembler: main.o parser.o
	$(CC) $(CFLAGS) main.o parser.o -o assembler

main.o: main.c parser.h
	$(CC) $(CFLAGS) -c main.c   -o main.o

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c -o parser.o

clean:
	rm -f assembler main.o parser.o

