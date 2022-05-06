#pragma once

#include "../Box/Box.hpp"
#include <vector>

using namespace std;

class Collision {
	public:
		Collision();

        bool testCollision(Box * player, vector <Box*> boxs, int playerNumber);
		char getCollision(Box * player, vector <Box*> boxs, int playerNumber);
        

	private:
};