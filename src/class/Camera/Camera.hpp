#pragma once

#define MaxX 50
#define MinX -50
#define MaxY 100
#define MinY -100

#include <vector>

#include <iostream>

#include "../utils/Vector/Vector.hpp"
#include "../utils/Area/Area.hpp"

using namespace std;

class Camera {
	public:
		Camera();

		Vector * playerMove(Vector * vecPos);
		Vector * getDelta();
		void testAreas(Vector * vecPos);
		void setUpAreas();

		//debug
		void showArea();
		
	private:
        Vector * delta;
        float zoom;
		float targetZoom;
		vector <Area*> areas;
};