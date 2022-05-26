#include "Elt.hpp"

using namespace std;

#include <iostream>

Elt::Elt(float x, float y, float width, float height) {
    origin = new Vector(x, y);
    childA = nullptr;
    childB = nullptr;
    childC = nullptr;
    childD = nullptr;
    nbBlocks = 0;
    w = width;
    h = height;

    block1 = nullptr;
    block2 = nullptr;
    block3 = nullptr;
    block4 = nullptr;
}

Vector * Elt::getOrigin(){
    return origin;
}

float Elt::getOriginX(){
    return origin->getX();
}

float Elt::getOriginY(){
    return origin->getY();
}

float Elt::getWidth(){
    return w;
}

float Elt::getHeight(){
    return h;
}

int Elt::getNbBlocks(){
    return nbBlocks;
}

Elt * Elt::getChildA(){
    return childA;
}

Elt * Elt::getChildB(){
    return childB;
}

Elt * Elt::getChildC(){
    return childC;
}

Elt * Elt::getChildD(){
    return childD;
}

bool Elt::isLeaf(){
    if (!childA && !childB && !childC && !childD){
        return true;
    }
    return false;
}

Block * Elt::getBlock1(){
    return block1;
}

Block * Elt::getBlock2(){
    return block2;
}

Block * Elt::getBlock3(){
    return block3;
}

Block * Elt::getBlock4(){
    return block4;
}

void Elt::insertTree(Block * block){
    
    if(isLeaf()){//is leaf
    
        if(nbBlocks >= 4 ){//leaf is full

            float w = getWidth()/2;
            float h = getHeight()/2;
            float ACx = getOriginX() - w/2;
            float ABy = getOriginY() + h/2;
            float BDx = getOriginX() + w/2;
            float CDy = getOriginY() - h/2;

            childA = new Elt(ACx, ABy, w, h);
            childB = new Elt(BDx, ABy, w, h);
            childC = new Elt(ACx, CDy, w, h);
            childD = new Elt(BDx, CDy, w, h);

            //insert again block
            insertTree(block);

            //move blocks that can't be in this node as it's not a leaf anymore
            insertTree(block1);
            insertTree(block2);
            insertTree(block3);
            insertTree(block4);
            block1 = nullptr;
            block2 = nullptr;
            block3 = nullptr;
            block4 = nullptr;
            nbBlocks = 0;

        }else{//leaf is not full

            if(block->getBox()->isIn(origin->getX(), origin->getY(), w, h)){
                if(nbBlocks == 0){
                    block1 = block;
                }else if(nbBlocks == 1){
                    block2 = block;
                }else if(nbBlocks == 2){
                    block3 = block;
                }else if(nbBlocks == 3){
                    block4 = block;
                }
                nbBlocks++;
            }
        }
    }else{//is not leaf

        if(block->getBox()->isIn(childA->origin->getX(), childA->origin->getY(), childA->getWidth(), childA->getHeight())){
            childA->insertTree(block);
        }
        if(block->getBox()->isIn(childB->origin->getX(), childB->origin->getY(), childB->getWidth(), childB->getHeight())){
            childB->insertTree(block);
        }
        if(block->getBox()->isIn(childC->origin->getX(), childC->origin->getY(), childC->getWidth(), childC->getHeight())){
            childC->insertTree(block);
        }
        if(block->getBox()->isIn(childD->origin->getX(), childD->origin->getY(), childD->getWidth(), childD->getHeight())){
            childD->insertTree(block);
        }
    }
}

vector<Block*> Elt::search(Vector pos){
    vector<Block*> blocks;

    if(isLeaf()){//is leaf
        for(int i = 0 ; i < getNbBlocks() ; i++){
            blocks.push_back(block1);
            blocks.push_back(block2);
            blocks.push_back(block3);
            blocks.push_back(block4);
        }
    }else{//not leaf
        if(pos.isIn(childA->getOriginX(), childA->getOriginY(), childA->getWidth(), childA->getHeight())){
            blocks.insert(blocks.end(), childA->search(pos).begin(), childA->search(pos).end());      
        }
        if(pos.isIn(childB->getOriginX(), childB->getOriginY(), childB->getWidth(), childB->getHeight())){
            blocks.insert(blocks.end(), childB->search(pos).begin(), childB->search(pos).end());
        }
        if(pos.isIn(childC->getOriginX(), childC->getOriginY(), childC->getWidth(), childC->getHeight())){
            blocks.insert(blocks.end(), childC->search(pos).begin(), childC->search(pos).end());
        }
        if(pos.isIn(childD->getOriginX(), childD->getOriginY(), childD->getWidth(), childD->getHeight())){
            blocks.insert(blocks.end(), childD->search(pos).begin(), childD->search(pos).end());
        }
    }
   
    return blocks;
}

//pas testée
vector<Elt *> Elt::getAllElt(vector<Elt *> elts, Elt * node){
    if(isLeaf()){
        elts.push_back(this);
    }else if(!isLeaf()){
        getAllElt(elts, childA);
        getAllElt(elts, childB);
        getAllElt(elts, childC);
        getAllElt(elts, childC);
    }
    return elts;
}