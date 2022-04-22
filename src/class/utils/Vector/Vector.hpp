#pragma once
#include <GL/glu.h>

using namespace std;

class Vector {
	public:
		Vector(float ux, float uy);
        
        float getX();
        float getY();
        float getZ();
		
	private:
        float x;
        float y;
        float z;
};