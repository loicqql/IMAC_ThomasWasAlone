#include "Elt.hpp"

#pragma once

using namespace std;

class Map {
	public:
		Map(float ua, float ub, float uc, float ud);

		float getA();
		float getB();
		float getC();
		float getD();

		Map getChildA();
		Map getChildB();
		Map getChildC();
		Map getChildD();

		bool isLeaf();

		Elt getElts();
		
	private:

		float a;
		float b;
		float c;
		float d;

		Map *childA;
		Map *childB;
		Map *childC;
		Map *childD;

		Elt * elts; //list of 2D elements composing the map, max 4 elements 
};