#include "Elt.hpp"

using namespace std;

Elt::Elt(float ux, float uy, float uw, float uh) {
    x = ux;
    y = uy;
    w = uw;
    h = uh;
}

float Elt::getX(){
    return x;
}

float Elt::getY(){
    return y;
}

float Elt::getW(){
    return w;
}

float Elt::getH(){
    return h;
}