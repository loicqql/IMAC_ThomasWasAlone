CC=g++
CFLAGS= -Wall -O2 -g
CFLAGSDEBUG=-DDEBUG -g
LDFLAGS	= -lSDL2 -lGLU -lGL -lm

game: build/main.o build/map.o build/player.o build/vector.o build/color.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

build/main.o: src/main.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/map.o: src/class/Map/Map.cpp src/class/Map/Map.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/player.o: src/class/Player/Player.cpp src/class/Player/Player.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/vector.o: src/class/utils/Vector/Vector.cpp src/class/utils/Vector/Vector.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/color.o: src/class/utils/Color/Color.cpp src/class/utils/Color/Color.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

clean: 
	rm -rf build/*.o
	rm -rf game
