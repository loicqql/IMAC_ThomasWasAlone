#pragma once

#include <vector>

#include "../Player/Player.hpp"
#include "../Block/Block.hpp"
#include "../Camera/Camera.hpp"
#include "../utils/Vector/Vector.hpp"
#include "../utils/Draw/Draw.hpp"

using namespace std;

class Game {
	public:
		Game();

		void movePlayer(Vector * vecInput);
		void render();
		void switchPlayer();
		
	private:
        Player players[4];
		Camera camera;
		Draw draw;
		Vector * deltaCamera;
		int playerNum;
		vector <Block*> blocks;

};