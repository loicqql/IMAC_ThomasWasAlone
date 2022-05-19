#include "../utils/Box/Box.hpp"
#include "../Block/Block.hpp"
#include "../utils/Vector/Vector.hpp"
#include "Elt.hpp"
#include "../utils/Draw/Draw.hpp"

#include <iostream>
#include <vector>

#pragma once

using namespace std;

class Map {
	public:
		Map(float width, float height, Elt * root);

        float getWidth();
        float getHeight();
		Elt * getRoot();
		void buildMap(vector<Block>);
		vector<Elt> getLeaves(Elt);
		void drawMap();

		vector<Block*> search(Vector);
		
	private:

		float w;
		float h;

        Elt * r;

		Draw draw;
};