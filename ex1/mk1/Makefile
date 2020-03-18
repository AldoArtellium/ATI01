CC=gcc
CFLAGS=-W -Wall -lncurses -lm -g
LDFLAGS=-W -Wall -lncurses -lm -g
EXEC=matrix

all: $(EXEC)

matrix: matrix.o menu.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

matrix.o: matrix.c
	$(CC) -o $@ -c $< $(CFLAGS)

menu.o: menu.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c matrix.h menu.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
