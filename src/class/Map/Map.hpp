#include "../utils/Box/Box.hpp"
#include "../Block/Block.hpp"
#include "../utils/Vector/Vector.hpp"
#include "Elt.hpp"
#include <iostream>
#include <vector>

#pragma once

using namespace std;

class Map {
	public:
		Map(float width, float height, Elt * root);

        float getWidth();
        float getHeight();
		void buildMap(vector<Block>);
		
	private:

		float w;
		float h;

        Elt * r;
};