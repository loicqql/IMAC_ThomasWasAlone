#include "Map.hpp"

using namespace std;

Map::Map(float width, float height, Elt * root){
    w = width;
    h = height;

    r = root;
}

float Map::getHeight(){
    return h;
}

float Map::getWidth(){
    return w;
}

void Map::buildMap(vector<Block> b){

    for(Block i : b){
        r->insert(i);
    }

}