#pragma once

#define INTRO 3
#define PLAY 2
#define PAUSE 1
#define START 0

#define STARTLEVEL1 101
#define STARTLEVEL2 102

#include <vector>

#include "../Player/Player.hpp"
#include "../Block/Block.hpp"
#include "../Camera/Camera.hpp"
#include "../Gui/Gui.hpp"
#include "../utils/Vector/Vector.hpp"
#include "../utils/Draw/Draw.hpp"
#include "../utils/Area/Area.hpp"
#include "../utils/Image/Image.hpp"

#include "../Ray/Ray.hpp"

using namespace std;

class Game {
	public:
		Game();

		void movePlayer(Vector * vecInput);
		void handleClick(Vector * vecClick);
		void render();
		void loadPlay();
		void loadIntro();
		void renderPlay();
		void renderPause();
		void renderStart();
		void renderIntro();
		void switchPlayer();
		void pauseGame();
		void handleAction();
		
	private:
        Player players[4];
		Camera camera;
		Gui gui;
		Draw draw;
		Vector * deltaCamera;
		int playerNum;
		int nbPlayers;
		vector <Block*> blocks;
		int mode;
		vector <Area*> actionAreas;

		Ray ray;
		Image image;
};