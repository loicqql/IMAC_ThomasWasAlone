#pragma once

using namespace std;

class Elt {
	public:
		Elt(float x, float y, float w, float h);

		float getX();
		float getY();
		float getW();
		float getH();
		
	private:
		float x;
		float y;
		float w;
		float h;
};