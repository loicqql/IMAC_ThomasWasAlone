#pragma once

#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

#include "../Block/Block.hpp"
#include "../utils/Vector/Vector.hpp"
#include "../utils/Collision/Collision.hpp"

using namespace std;

class Ray {
	public:

		Ray();

        void render();
        void setBlocks(vector <Block*> blks);
        void setDelta(Vector * delta);
        void test(Vector * vec);

	private:
        vector <Block*> blocks;
        Collision collision;
        Vector * vecPos;
        Vector * deltaCamera;
};