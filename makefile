CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
OBJ=main.o graphic.o plateau.o taquin.o

taquin: $(OBJ)
	$(CC) -o taquin $(OBJ) $(CFLAGS) -lMLV

graphic.o: graphic.c graphic.h
	$(CC) -c graphic.c $(CFLAGS) -lMLV

plateau.o: plateau.c plateau.h
	$(CC) -c plateau.c $(CFLAGS)

taquin.o: taquin.c taquin.h
	$(CC) -c taquin.c $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f taquin
