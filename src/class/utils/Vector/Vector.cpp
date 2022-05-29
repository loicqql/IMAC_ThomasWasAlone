#include "Vector.hpp"

using namespace std;

Vector::Vector(float ux, float uy) {
    x = ux;
    y = uy;
    z = 1.0;
}

float Vector::getX() {
    return x;
}

float Vector::getY() {
    return y;
}

float Vector::getZ() {
    return z;
}

float Vector::getAngle() {
    return angle;
}

void Vector::setZ(float nb) {
    z = nb;
}

void Vector::setAngle(float nb) {
    angle = nb;
}

void Vector::add(Vector vec) {
    x += vec.getX();
    y += vec.getY();
}

void Vector::subtract(Vector vec) {
    x -= vec.getX();
    y -= vec.getY();
}

bool Vector::isIn(float areaX, float areaY, float w, float h){
    if(x >= areaX-w/2 && x <= areaX + w/2 && y >= areaY - h/2 && y <= areaY+h/2){
        return true;
    }
    return false;    
}