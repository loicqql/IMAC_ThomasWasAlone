#pragma once

#include "../../Block/Block.hpp"
#include "../Box/Box.hpp"
#include "../Vector/Vector.hpp"
#include <vector>

#include <iostream>

using namespace std;

class Collision {
	public:
		Collision();

        bool testCollision(Box * player, vector <Block*> blocks, int playerNumber);
		char getCollision(Box * player, vector <Block*> blocks, int playerNumber);
        bool rayIntersection(vector <Block*> blocks, Vector * vec);

	private:
};