#pragma once

#include "../../Block/Block.hpp"
#include "../Box/Box.hpp"
#include <vector>

using namespace std;

class Collision {
	public:
		Collision();

        bool testCollision(Box * player, vector <Block*> blocks, int playerNumber);
		char getCollision(Box * player, vector <Block*> blocks, int playerNumber);
        

	private:
};