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
		Map(float width, float height);

        float getWidth();
        float getHeight();
		Elt * getRoot();
		void buildMap(vector<Block*>);
		vector<Elt *> getLeaves(Elt * node);
		vector<Elt *> getLeaves(vector<Elt *> leaves, Elt * node);
		//vector<Block*> * getLeaves(vector<Block*> * bLeaves, Elt * node);
		void drawMap(vector<Elt *> leaves);

		vector<Block*> search(Vector);

		vector<Elt *> allElt();
		
	private:

		float w;
		float h;

        Elt * r;

		Draw draw;
};