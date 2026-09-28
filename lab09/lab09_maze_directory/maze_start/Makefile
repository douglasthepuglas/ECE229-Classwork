# Builds the maze from its source files.
#
#   make          build ./maze.exe
#   make clean    delete what was built
#
# Each .c is compiled on its own into a .o, and the .o files are linked
# together at the end. Every rule lists maze.h too, so changing the header
# rebuilds the files that include it -- which is the whole reason the header
# is listed rather than assumed.
#
# The indented lines below MUST start with a tab, not spaces. Make is strict
# about this and the error it gives if you use spaces is not a helpful one.

CC     = gcc
CFLAGS = -Wall -Wextra -std=c99

maze.exe: main.o generate.o solve.o print.o
	$(CC) main.o generate.o solve.o print.o -o maze.exe

main.o: main.c maze.h
	$(CC) $(CFLAGS) -c main.c -o main.o

generate.o: generate.c maze.h
	$(CC) $(CFLAGS) -c generate.c -o generate.o

solve.o: solve.c maze.h
	$(CC) $(CFLAGS) -c solve.c -o solve.o

print.o: print.c maze.h
	$(CC) $(CFLAGS) -c print.c -o print.o

clean:
	rm -f maze.exe main.o generate.o solve.o print.o
