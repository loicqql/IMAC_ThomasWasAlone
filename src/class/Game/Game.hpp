#pragma once

#include <iostream>

#include "../Player/Player.hpp"
#include "../Camera/Camera.hpp"
#include "../utils/Vector/Vector.hpp"

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
		Vector * deltaCamera;
		int playerNum;

};