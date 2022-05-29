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

void Box::setW(float uw) {
    w = uw;
}

void Box::setH(float uh) {
    h = uh;
}

void Box::setX(float ux) {
    x = ux;
}

void Box::setY(float uy) {
    y = uy;
}

bool Box::isIn(float areaX, float areaY, float width, float height){
    if(x-w/2 < areaX + width/2 && x+w/2 > areaX - width/2 && y+h/2 > areaY-height/2 && y-h/2 < areaY + height/2){
        return true;
    }
    return false;    
} 