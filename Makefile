 
CC=g++
CFLAGS=-I. -I./source
OBJ = obj/main.o obj/degrees.o

all: $(OBJ)
	$(CC) $(OBJ) -o delta

obj/main.o: main.cpp
	$(CC) $(CFLAGS) -c -o obj/main.o main.cpp

obj/degrees.o: src/degrees.cpp
	$(CC) $(CFLAGS) -c -o obj/degrees.o src/degrees.cpp

#obj/JulianDay.o : source/JulianDay.h source/JulianDay.cpp
#	$(CC) $(CFLAGS) -c -o obj/JulianDay.o source/JulianDay.cpp

#obj/SolarPhysics.o : source/SolarPhysics.h source/SolarPhysics.cpp
#	$(CC) $(CFLAGS) -c -o obj/SolarPhysics.o source/SolarPhysics.cpp

clean:
	rm -rf obj/*.o
	rm delta
