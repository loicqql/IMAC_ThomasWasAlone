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
		
	private:
        Vector *pos;
        Color *color;
		Box *box;
		float w;
		float h;
		float ax;
		float ay;
		bool canJump;

		bool collision();
		bool testCollision(Box * box1, Box * box2);
		bool resetJump(Box * player, Box * box);
};