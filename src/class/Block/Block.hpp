#pragma once

#include "../utils/Box/Box.hpp"

using namespace std;

class Block {
	public:
		Block(Box * aBox);

		Box * getBox();


	private:
		Box * box;
        
};