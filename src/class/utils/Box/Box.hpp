#pragma once

using namespace std;

class Box {
	public:
		Box(float uw, float uh, float ux, float uy);
        
        float getW();
        float getH();
		float getX();
        float getY();
        void setX(float ux);
        void setY(float uy);
        void setW(float uw);
        void setH(float uh);
        bool isIn(float areaX, float areaY, float width, float height);

	private:
        float w;
        float h;
        float x;
        float y;
};