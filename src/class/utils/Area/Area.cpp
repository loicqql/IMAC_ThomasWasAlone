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

void Area::setX(float ux) {
    x = ux;
}

void Area::setY(float uy) {
    y = uy;
}

void Area::setZoom(float uzoom) {
    zoom = uzoom;
}