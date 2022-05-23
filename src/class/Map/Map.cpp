#include "Map.hpp"

#include <iostream>

using namespace std;

Map::Map(float width, float height){
    w = width;
    h = height;

    r = new Elt(0, 0, w, h);
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
        //cout << "getX" << i.getBox()->getY() << endl;
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

vector<Block*> Map::search(Vector pos){
    return r->search(pos);
}

// vector<Block*> Map::search(Elt node, Vector pos){

//     vector<Block*> blocks;

//     if(pos.getX() <= w && pos.getY() <= h){//is in map
//         if(node.isLeaf()){
//             for(int i = 0 ; i < node.getNbBlocks() ; i++){
//                 blocks.push_back(node.getBlocks()[i]);
//             }
//         }else{
//             if(pos.isIn(node.getchildA()->getX(), childA.getY(), childA.getWidth(), childA.getHeight())){
//                 childA.search(pos);
//             }
//             if(pos.isIn(node.getchildB()->getX(), childB.getY(), childB.getWidth(), childB.getHeight())){
//                 childB.search(pos);
//             }
//             if(pos.isIn(node.getchildB()->getX(), childC.getY(), childC.getWidth(), childC.getHeight())){
//                 childC.search(pos);
//             }
//             if(pos.isIn(childD.getX(), childD.getY(), childD.getWidth(), childD.getHeight())){
//                 childD.search(pos);
//             }
//         }
//     }else{//not in map
//         return nullptr;
//     }


//     return blocks;
// }

void Map::drawMap(){
    vector<Elt> leaves = getLeaves(*r);

    for(uint i = 0 ; i < leaves.size() ; i++){
        for(int j = 0 ; j < leaves[i].getNbBlocks() ; j++){
            draw.render(&(leaves[i].getBlocks()[j]));
        }
    }
}