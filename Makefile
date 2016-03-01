CC=g++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++0x -Wall

all: tetris

tetris: test.o graphics.o block.o tetriminos.o playingField.o
	$(CC) $(CFLAGS) main.o graphics.o block.o tetriminos.o playingField.o -o tetris

test.o: test.cpp
	$(CC) -c $(CFLAGS) test.cpp -o main.o

graphics.o: graphics.cpp
	$(CC) -c $(CFLAGS) graphics.cpp

block.o: block.cpp
	$(CC) -c $(CFLAGS) block.cpp

tetriminos.o: tetriminos.cpp
	$(CC) -c $(CFLAGS) tetriminos.cpp

playingField.o: playingField.cpp
	$(CC) -c $(CFLAGS) playingField.cpp

clean:
	rm *.o tetris

