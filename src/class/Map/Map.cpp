#include "Map.hpp"

using namespace std;

Map::Map(float ua, float ub, float uc, float ud) {
    a = ua;
    b = ub;
    c = uc;
    d = ud;
}

float Map::getA(){
    return a;
}

float Map::getB(){
    return b;
}

float Map::getC(){
    return c;
}

float Map::getD(){
    return d;
}

Map Map::getChildA(){
    return *childA;
}

Map Map::getChildB(){
    return *childB;
}

Map Map::getChildC(){
    return *childC;
}

Map Map::getChildD(){
    return *childD;
}

bool Map::isLeaf(){
    if(childA && childB && childC && childD){
        return true;
    }
    return false;
}

Elt Map::getElts(){
    return *elts;
}