CC = gcc -ansi -pedantic -Wall -Wextra
SRC = $(wildcard *.c)
HDR = $(wildcard *.h)
OBJ = $(SRC:%.c=%.o)


prog: $(OBJ)
	$(CC) -o prog $(OBJ)

%.o: %.c
	$(CC) -c $<
