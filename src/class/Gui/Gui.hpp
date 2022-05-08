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

class Gui {
	public:
		Gui();

		bool testAreas(Vector * vecClick);
		void setUpAreasStart();
        void setUpAreasPause();
        void showStart();
        void showPause();

		//debug
		void showArea();
		
	private:
		vector <Area*> areas;
        int mode;
};