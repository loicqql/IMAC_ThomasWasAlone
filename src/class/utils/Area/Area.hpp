#pragma once

using namespace std;

#include "../Vector/Vector.hpp"

class Area {
	public:
		Area(float uw, float uh, float ux, float uy, float uzoom);
        
        float getW();
        float getH();
		float getX();
        float getY();
        float getZoom();
        int getAction();
        void setX(float ux);
        void setY(float uy);
        void setZoom(float uzoom);
        void setAction(float uaction);
        bool test(Vector * vec);

	private:
        float w;
        float h;
        float x;
        float y;
        float zoom;
        int action;
};