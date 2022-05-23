#include "Box.hpp"

using namespace std;

Box::Box(float uw, float uh, float ux, float uy) {
    w = uw;
    h = uh;
    x = ux;
    y = uy;
}

float Box::getW() {
    return w;
}

float Box::getH() {
    return h;
}

float Box::getX() {
    return x;
}

float Box::getY() {
    return y;
}

void Box::setX(float ux) {
    x = ux;
}

void Box::setY(float uy) {
    y = uy;
}

bool Box::isIn(float areaX, float areaY, float w, float h){
    if(x-w/2 < areaX + w && x+w/2 > areaX && y-h/2 < areaY + h && y+h/2 > areaY){
        return true;
    }
    return false;    
}