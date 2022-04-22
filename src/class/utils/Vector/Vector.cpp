#include "Vector.hpp"

using namespace std;

Vector::Vector(float ux, float uy) {
    x = ux;
    y = uy;
}

float Vector::getX() {
    return x;
}

float Vector::getY() {
    return y;
}

void Vector::add(Vector vec) {
    x += vec.getX();
    y += vec.getY();
}

void Vector::subtract(Vector vec) {
    x -= vec.getX();
    y -= vec.getY();
}