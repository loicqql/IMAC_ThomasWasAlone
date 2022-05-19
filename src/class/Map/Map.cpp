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

Elt * Map::getRoot(){
    return r;
}

void Map::buildMap(vector<Block> b){

    for(Block i : b){
        r->insert(i);
    }

}

vector<Elt> Map::getLeaves(Elt node){
    vector<Elt> leaves;
    if(node.isLeaf()){
        leaves.push_back(node);
    }
    if(!node.isLeaf()){
        getLeaves(node.getChildA());
        getLeaves(node.getChildB());
        getLeaves(node.getChildC());
        getLeaves(node.getChildD());
    }

    return leaves;
}

void Map::drawMap(){
    vector<Elt> leaves = getLeaves(*r);

    for(uint i = 0 ; i < leaves.size() ; i++){
        for(int j = 0 ; j < leaves[i].getNbBlocks() ; j++){
            draw.render(&(leaves[i].getBlocks()[j]));
        }
    }
}