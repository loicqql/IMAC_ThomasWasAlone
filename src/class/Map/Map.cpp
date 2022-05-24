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

void Map::buildMap(vector<Block*> b){
    for(Block * i : b){
        //cout << "getX" << i.getBox()->getY() << endl;
        r->insertTree(i);
    }

}

// vector<Elt *> Map::getLeaves(vector<Elt *> leaves, Elt * node){
//     if(node->isLeaf() && node->getNbBlocks() > 0 && node != 0x0){
//         leaves.push_back(node);
//         cout << "added a leaf" << endl;
//     }else if(!node->isLeaf()){
//         getLeaves(leaves, node->getChildA());
//         getLeaves(leaves, node->getChildB());
//         getLeaves(leaves, node->getChildC());
//         getLeaves(leaves, node->getChildD());
//     }
//     return leaves;
// }

vector<Block*> * Map::getLeaves(vector<Block*> * leaves, Elt * node){
    
    if(node->isLeaf() && node->getNbBlocks() > 0 && node != 0x0){
        Block * blocks = node->getBlocks();
        for(int i = 0 ; i < node->getNbBlocks() ; i++){
            leaves->push_back(&(blocks[i]));
        }   
    }
    if(!node->isLeaf()){
        getLeaves(leaves, node->getChildA());
        getLeaves(leaves, node->getChildB());
        getLeaves(leaves, node->getChildC());
        getLeaves(leaves, node->getChildD());
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

void Map::drawMap(vector<Block *> leaves){
    // for(uint i = 0 ; i < getLeaves(bLeaves, r).size() ; i++){
    //     bLeaves->push_back(getLeaves(bLeaves, r)[i]);
    // }
    //cout << "is empty? " << leaves.size() << endl;
    //cout << "leaves : " << bLeaves[0]->getBlocks()[0].getBox()->getY() << endl;
    
    //draw.render(&(leaves[0].getBlocks()[0]));

    // vector <Block*> allBlocks;

    // for(uint i = 0 ; i < leaves.size() ; i++){
    //     for(int j = 0 ; j < leaves.at(i)->getNbBlocks() ; j++){
    //         allBlocks.push_back(leaves[i]->getBlocks()[i]);
    //     }
    // }

    draw.render(leaves);
}

vector<Elt *> Map::allElt(){
    vector<Elt *> elts;
    return r->getAllElt(elts, r);
}