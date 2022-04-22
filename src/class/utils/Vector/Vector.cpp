#include "Vector.hpp"

using namespace std;

Vector::Vector(float ux, float uy) {
    x = ux;
    y = uy;
    z = 0.0;
}

float Vector::getX() {
    return x;
}

float Vector::getY() {
    return y;
}