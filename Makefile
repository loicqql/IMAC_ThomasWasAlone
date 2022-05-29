CC=g++
CFLAGS= -Wall -O2 -g
CFLAGSDEBUG=-DDEBUG -g
LDFLAGS	= -lSDL2 -lSDL2_image -lGLU -lGL -lm

game: build/main.o build/game.o build/block.o build/map.o build/elt.o build/win.o build/player.o build/ray.o build/camera.o build/gui.o build/vector.o build/color.o build/box.o build/draw.o build/collision.o build/area.o build/image.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

build/main.o: src/main.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/game.o: src/class/Game/Game.cpp src/class/Game/Game.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/block.o: src/class/Block/Block.cpp src/class/Block/Block.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/map.o: src/class/Map/Map.cpp src/class/Map/Map.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/elt.o: src/class/Map/Elt.cpp src/class/Map/Elt.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/player.o: src/class/Player/Player.cpp src/class/Player/Player.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/camera.o: src/class/Camera/Camera.cpp src/class/Camera/Camera.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/vector.o: src/class/utils/Vector/Vector.cpp src/class/utils/Vector/Vector.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/gui.o: src/class/Gui/Gui.cpp src/class/Gui/Gui.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/ray.o: src/class/Ray/Ray.cpp src/class/Ray/Ray.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/win.o: src/class/Win/Win.cpp src/class/Win/Win.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/color.o: src/class/utils/Color/Color.cpp src/class/utils/Color/Color.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/box.o: src/class/utils/Box/Box.cpp src/class/utils/Box/Box.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/draw.o: src/class/utils/Draw/Draw.cpp src/class/utils/Draw/Draw.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/collision.o: src/class/utils/Collision/Collision.cpp src/class/utils/Collision/Collision.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/area.o: src/class/utils/Area/Area.cpp src/class/utils/Area/Area.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

build/image.o: src/class/utils/Image/Image.cpp src/class/utils/Image/Image.hpp
	$(CC) $(CFLAGS) -o $@ -c $< $(LDFLAGS)

clean: 
	rm -rf build/*.o
	rm -rf game