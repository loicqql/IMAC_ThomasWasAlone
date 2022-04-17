CC=g++
CFLAGS=-Wall -ansi
CFLAGSDEBUG=-DDEBUG -g
LDFLAGS	= -lSDL2 -lGLU -lGL -lm

game: build/main.o build/map.o
	$(CC) -o $@ $^ $(LDFLAGS)

build/main.o: src/main.cpp
	$(CC) -o $@ -c $< $(LDFLAGS)

build/map.o: src/class/Map/Map.cpp src/class/Map/Map.hpp
	$(CC) -o $@ -c $< $(LDFLAGS)

clean: 
	rm -rf build/*.o
	rm -rf game
