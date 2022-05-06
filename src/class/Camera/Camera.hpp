#pragma once

#include <iostream>

#define MaxX 50
#define MinX -50
#define MaxY 100
#define MinY -100

#include "../utils/Vector/Vector.hpp"

using namespace std;

class Camera {
	public:
		Camera();

		Vector * playerMove(Vector * vecPos);
		Vector * getDelta();
		
	private:
        Vector * delta;
        float zoom;
};