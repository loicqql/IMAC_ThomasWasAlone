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

		Block * getBlock1();
		Block * getBlock2();
		Block * getBlock3();
		Block * getBlock4();

		bool isLeaf();
		void insertTree(Block*);

		vector<Block*> search(Vector*);
		void insertBlocks(Elt * area, vector<Block*> * vector);

		vector<Elt *> getAllElt(vector<Elt *> elts, Elt * node);
		
	private:

		Vector *origin;
		float w;
		float h;

		Elt *childA;
		Elt *childB;
		Elt *childC;
		Elt *childD;

		int nbBlocks;
		
		Block *block1;
		Block *block2;
		Block *block3;
		Block *block4;
};