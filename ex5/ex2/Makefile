CC=gcc
CFLAGS=-W -Wall -lncurses -lm -g
LDFLAGS=-W -Wall -lncurses -lm -g
EXEC=factorielle

all: $(EXEC)

factorielle: factorielle.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

factorielle.o: factorielle.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c factorielle.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
