#pragma once

#include <iostream>

#include "../Map/Map.hpp"
#include "../utils/Vector/Vector.hpp"
#include "../utils/Color/Color.hpp"
#include "../utils/Box/Box.hpp"

using namespace std;

class Player {
	public:
		Player();

		void render();
		void move(Vector *vecInput, Map *map);
		
	private:
        Vector *pos;
        Color *color;
		Box *box;
		float w;
		float h;
		float ax;
		float ay;

		bool collision();
};