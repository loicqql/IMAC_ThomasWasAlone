#include "Elt.hpp"

using namespace std;

Elt::Elt(float x, float y, float width, float height) {
    origin = new Vector(x, y);
    childA = nullptr;
    childB = nullptr;
    childC = nullptr;
    childD = nullptr;
    nbBlocks = 0;
    w = width;
    h = height;

    blocks = nullptr;
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

Elt Elt::getChildA(){
    return *childA;
}

Elt Elt::getChildB(){
    return *childB;
}

Elt Elt::getChildC(){
    return *childC;
}

Elt Elt::getChildD(){
    return *childD;
}

bool Elt::isLeaf(){
    if (childA == nullptr && childB == nullptr && childC == nullptr && childD == nullptr){
        return true;
    }
    return false;
}

Block Elt::getBlocks(){
    return *blocks;
}

// vector <Block*> Elt::getNeighbours(){

// }

void Elt::insert(Block block){
    if(isLeaf()){//is leaf
        if(nbBlocks >= 4){//leaf is full

            float w = getWidth()/2;
            float h = getHeight()/2;
            float ACx = getOriginX();
            float ABy = getOriginY();
            float BDx = getOriginX() + (getWidth()/2) + 1;
            float CDy = getOriginY() + (getHeight()/2) + 1;

            childA = new Elt(ACx, ABy, w, h);
            childB = new Elt(BDx, ABy, w-1, h);
            childC = new Elt(ACx, CDy, w, h-1);
            childD = new Elt(BDx, CDy, w-1, h-1);

            if(block.getBox()->isIn(ACx, ABy, w, h)){//isIn(childA) ?
                childA->blocks[0] = block;
                childA->nbBlocks++;
            }
            if(block.getBox()->isIn(BDx, ABy, w-1, h)){//isIn(childB) ?
                childB->blocks[0] = block;
            }
            if(block.getBox()->isIn(ACx, CDy, w, h-1)){//isIn(childC) ?
                childC->blocks[0] = block;
            }
            if(block.getBox()->isIn(BDx, CDy, w-1, h-1)){//isIn(childD) ?
                childD->blocks[0] = block;
            }

        }else{//leaf is not full

            if(block.getBox()->isIn(origin->getX(), origin->getY(), w, h)){
                blocks[nbBlocks] = block;
                nbBlocks++;
            }

        }
    }else{//is not leaf



    }
}