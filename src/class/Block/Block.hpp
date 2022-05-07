#pragma once

#include "../utils/Box/Box.hpp"
#include "../utils/Vector/Vector.hpp"

using namespace std;

class Block {
	public:
		Block(Box * aBox);

		Box * getBox();
		void updateMovement();
		void setPosA(Vector * pos);
		void setPosB(Vector * pos);
		void setSteps(float nb);

	private:
		Box * box;
        Vector * posA;
		Vector * posB;
		float steps;
};