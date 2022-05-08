#pragma once

#define PLAY 2
#define PAUSE 1
#define START 0

#include <vector>

#include "../Player/Player.hpp"
#include "../Block/Block.hpp"
#include "../Camera/Camera.hpp"
#include "../Gui/Gui.hpp"
#include "../utils/Vector/Vector.hpp"
#include "../utils/Draw/Draw.hpp"

#include "../Ray/Ray.hpp"

using namespace std;

class Game {
	public:
		Game();

		void movePlayer(Vector * vecInput);
		void handleClick(Vector * vecClick);
		void render();
		void renderPlay();
		void renderPause();
		void renderStart();
		void switchPlayer();
		void pauseGame();
		
	private:
        Player players[4];
		Camera camera;
		Gui gui;
		Draw draw;
		Vector * deltaCamera;
		int playerNum;
		vector <Block*> blocks;
		int mode;

		Ray ray;
};