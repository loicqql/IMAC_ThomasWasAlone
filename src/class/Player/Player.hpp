#pragma once

#include "../utils/Vector/Vector.hpp"
#include "../utils/Color/Color.hpp"

using namespace std;

class Player {
	public:
		Player();

		void render();
		
	private:
        Vector *pos;
        Vector *dim;
        Color *color;
};