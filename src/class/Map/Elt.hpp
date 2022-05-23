#include "../utils/Box/Box.hpp"
#include "../Block/Block.hpp"
#include "../utils/Vector/Vector.hpp"

#include <vector>

#pragma once

using namespace std;

class Elt {
	public:
		Elt(float x, float y, float width, float height);

		Vector * getOrigin();
		float getOriginX();
		float getOriginY();
		float getWidth();
		float getHeight();
		int getNbBlocks();

		Elt * getChildA();
		Elt * getChildB();
		Elt * getChildC();
		Elt * getChildD();

		bool isLeaf();
		Block * getBlocks();
		void insert(Block);

		vector<Block*> search(Vector);
		
	private:

		Vector *origin;
		float w;
		float h;

		Elt *childA;
		Elt *childB;
		Elt *childC;
		Elt *childD;

		int nbBlocks;
		Block * blocks[4]; //list of 2D elements composing the map, max 4 elements 
};