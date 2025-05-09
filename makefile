CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
OBJ=main.o graphic.o taquin.o

taquin: $(OBJ)
	$(CC) -o taquin $(OBJ) $(CFLAGS) -lMLV

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

graphic.o: graphic.c graphic.h
	$(CC) -c graphic.c $(CFLAGS) -lMLV

taquin.o: taquin.c taquin.h
	$(CC) -c taquin.c $(CFLAGS)
clean:
	rm -f *.o
	rm -f *~
	rm -f sudoku
