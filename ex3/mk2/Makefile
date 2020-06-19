CC=gcc
CFLAGS=-W -Wall -lm -g
LDFLAGS=-W -Wall -lm -g
EXEC=polynome

all: $(EXEC)

polynome: polynome.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

polynome.o: polynome.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c polynome.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
