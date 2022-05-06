#pragma once

#include <iostream>

#include <vector>

#include "../Block/Block.hpp"
#include "../utils/Vector/Vector.hpp"
#include "../utils/Color/Color.hpp"
#include "../utils/Box/Box.hpp"
#include "../utils/Collision/Collision.hpp"

using namespace std;

class Player {
	public:
		Player();

		void render();
		void move(Vector *vecInput);
		Vector * getPos();
		void setDelta(Vector * delta);
		void setColor(Color * newColor);
		void drawTriangle();
		void setBlocks(vector <Block*> blks);
		Box * getBox();
		void setPos(Vector * vecPos);
		void setPlayerNumber(int nb);
		
	private:
        Vector *pos;
        Color *color;
		Box *box;
		float w;
		float h;
		float ax;
		float ay;
		bool canJump;
		Vector * deltaCamera;
		Collision collision;
		vector <Block*> blocks;
		int playerNumber;

};