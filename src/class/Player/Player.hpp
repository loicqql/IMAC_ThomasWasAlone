#pragma once

#include <iostream>

#include "../utils/Vector/Vector.hpp"
#include "../utils/Color/Color.hpp"
#include "../utils/Box/Box.hpp"

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
		
	private:
        Vector *pos;
        Color *color;
		Box *box;
		float w;
		float h;
		float ax;
		float ay;
		bool canJump;
		char col;
		Vector * deltaCamera;

		bool collision();
		char getCollision(Box * player, Box * box);
};