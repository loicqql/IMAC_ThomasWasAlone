#include "Area.hpp"

using namespace std;

Area::Area(float uw, float uh, float ux, float uy, float uzoom) {
    w = uw;
    h = uh;
    x = ux;
    y = uy;
    zoom = uzoom;
}

float Area::getW() {
    return w;
}

float Area::getH() {
    return h;
}

float Area::getX() {
    return x;
}

float Area::getY() {
    return y;
}

float Area::getZoom() {
    return zoom;
}

int Area::getAction() {
    return action;
}

void Area::setX(float ux) {
    x = ux;
}

void Area::setY(float uy) {
    y = uy;
}

void Area::setZoom(float uzoom) {
    zoom = uzoom;
}

void Area::setAction(float uaction) {
    action = uaction;
}

bool Area::test(Vector * vec) {
    float hW = getW() / 2;
	float hH = getH() / 2;
    if((vec->getX() > getX() - hW) && (vec->getX() < getX() + hW)) {
        if((vec->getY() > getY() - hH) && (vec->getY() < getX() + hH)) {
            return true;
        }
    }

    return false;
}