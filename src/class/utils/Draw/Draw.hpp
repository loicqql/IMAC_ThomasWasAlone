#pragma once

#include "../Box/Box.hpp"
#include "../Color/Color.hpp"
#include "../Vector/Vector.hpp"

#include <vector>

using namespace std;

class Draw {
	public:
		Draw();

        void setDelta(Vector * delta);
        void render(vector <Box*> boxs);
        void render(Box * oneBox);      

	private:
        Vector * deltaCamera;
};