#pragma once
#include <GL/glu.h>

using namespace std;

class Vector {
	public:
        Vector(float ux, float uy);
        
        float getX();
        float getY();
        float getZ();

        void setZ(float nb);

        void add(Vector vec);
        void subtract(Vector vec); 

        bool isIn(float areaX, float areaY, float w, float h);
		
	private:
        float x;
        float y;
        float z;
};