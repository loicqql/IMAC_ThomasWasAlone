#pragma once

using namespace std;

class Color {
	public:
		Color(double ur, double ug, double ub);
        Color(int ur, int ug, int ub);
        
        float getR();
        float getG();
        float getB();
		
	private:
        float r;
        float g;
        float b;
};