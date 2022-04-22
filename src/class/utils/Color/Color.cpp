#include "Color.hpp"

using namespace std;

Color::Color(double ur, double ug, double ub) {
    r = ur > 1.0 ? 1.0 : ur;
    g = ug > 1.0 ? 1.0 : ug;
    b = ub > 1.0 ? 1.0 : ub;
}

Color::Color(int ur, int ug, int ub) {
    r = ur > 255 ? 255.0 : ur / 255.0;
    g = ug > 255 ? 255.0 : ug / 255.0;
    b = ub > 255 ? 255.0 : ub / 255.0;
}

/*
Color::Color(string hexa); {
    x = ux;
    y = uy;
    z = 0.0;
} */

float Color::getR() {
    return r;
}

float Color::getG() {
    return g;
}

float Color::getB() {
    return b;
}