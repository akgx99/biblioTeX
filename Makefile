CC=gcc
CFLAGS=-Wall -O
LDFLAGS=
EXEC= biblioTeX
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

biblioTeX: $(OBJ)
				$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
				$(CC) -o $@ -c $< $(CFLAGS)

clean:
				rm -f *.o core

mrproper: clean
				rm -f $(EXEC)