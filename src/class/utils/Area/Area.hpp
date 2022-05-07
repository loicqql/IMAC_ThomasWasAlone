#pragma once

using namespace std;

class Area {
	public:
		Area(float uw, float uh, float ux, float uy, float uzoom);
        
        float getW();
        float getH();
		float getX();
        float getY();
        float getZoom();
        void setX(float ux);
        void setY(float uy);
        void setZoom(float uzoom);

	private:
        float w;
        float h;
        float x;
        float y;
        float zoom;
};