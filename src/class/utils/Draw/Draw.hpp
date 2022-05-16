#pragma once

#include "../../Block/Block.hpp"
#include "../Box/Box.hpp"
#include "../Color/Color.hpp"
#include "../Vector/Vector.hpp"

#include <vector>

using namespace std;

class Draw {
	public:
		Draw();

		void setDelta(Vector * delta);
		void render(vector <Block*> blocks, int nbPlayers);
		void render(Block * block);      

	private:
		Vector * deltaCamera;
};