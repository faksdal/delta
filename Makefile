 
CC=g++
CFLAGS=-I. -I./source
OBJ = obj/main.o obj/degrees.o

all: $(OBJ)
	$(CC) $(OBJ) -o delta

obj/main.o: main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o main.cpp

obj/degrees.o: src/degrees.cpp
	$(CC) $(CFLAGS) -c -o obj/degrees.o src/degrees.cpp

clean:
	rm -rf obj/*.o
	rm delta
