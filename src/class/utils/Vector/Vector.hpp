#pragma once
#include <GL/glu.h>

using namespace std;

class Vector {
	public:
        Vector(float ux, float uy);
        
        float getX();
        float getY();

        float getZ();
        float getAngle();

        void setZ(float nb);
        void setAngle(float nb);

        void add(Vector vec);
        void subtract(Vector vec); 

        
		
	private:
        float x;
        float y;
        float z;
        float angle;
};