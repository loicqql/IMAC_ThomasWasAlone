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

    blocks[0] = nullptr;
    blocks[1] = nullptr;
    blocks[2] = nullptr;
    blocks[3] = nullptr;
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
    // if (childA == nullptr && childB == nullptr && childC == nullptr && childD == nullptr){
    //     return true;
    // }
    if (childA == 0x0 && childB == 0x0 && childC == 0x0 && childD == 0x0){
        return true;
    }
    return false;
}

Block * Elt::getBlocks(){
    return *blocks;
}

void Elt::insertTree(Block * block){

    cout << "nb blocks debut : " << nbBlocks << endl;
    
    if(isLeaf()){//is leaf
    
        if(nbBlocks >= 4 ){//leaf is full

            cout << "leaf full -- debut" << endl << "------------CREER DES ENFANTS"<<endl;

            float w = getWidth()/2;
            float h = getHeight()/2;
            float ACx = getOriginX();
            float ABy = getOriginY();
            float BDx = getOriginX() + (getWidth()/2) + 1;
            float CDy = getOriginY() + (getHeight()/2) + 1;

            childA = new Elt(ACx, ABy, w, h);

            cout << "nb blocks childA : " << childA->getNbBlocks() << endl;
            childB = new Elt(BDx, ABy, w-1, h);
            childC = new Elt(ACx, CDy, w, h-1);
            childD = new Elt(BDx, CDy, w-1, h-1);

            
            //insert again block
            insertTree(block);

            //move blocks that can't be in this node as it's not a leaf anymore
            for(int i = 0 ; i < nbBlocks ; i++){
                insertTree(blocks[i]);
                blocks[i] = nullptr;
            }
            nbBlocks = 0;

            cout << "leaf full -- fin" << endl;

        }else{//leaf is not full

            cout << "leaf not full -- debut" << endl;

            if(block->getBox()->isIn(origin->getX(), origin->getY(), w, h)){
                blocks[nbBlocks] = block;
                nbBlocks++;
                cout << nbBlocks << endl;
            }
            cout << "leaf not full -- fin" << endl;

        }
    }else{//is not leaf

        cout << "is not leaf -- debut" << endl;

        cout << "isinB ? "<< block->getBox()->isIn(childB->origin->getX(), childB->origin->getY(), childB->getWidth(), childB->getHeight()) << endl;

        if(block->getBox()->isIn(childA->origin->getX(), childA->origin->getY(), childA->getWidth(), childA->getHeight())){
            cout << "isinA" << endl;
            childA->insertTree(block);
        }
        if(block->getBox()->isIn(childB->origin->getX(), childB->origin->getY(), childB->getWidth(), childB->getHeight())){
            cout << "isinB" << endl;
            childB->insertTree(block);
        }
        if(block->getBox()->isIn(childC->origin->getX(), childC->origin->getY(), childC->getWidth(), childC->getHeight())){
            cout << "isinC" << endl;
            childC->insertTree(block);
        }
        if(block->getBox()->isIn(childD->origin->getX(), childD->origin->getY(), childD->getWidth(), childD->getHeight())){
            cout << "isinD" << endl;
            childD->insertTree(block);
        }

        cout << "is not leaf -- fin" << endl;

    }
}

vector<Block*> Elt::search(Vector pos){
    vector<Block*> blocks;

    if(isLeaf()){//is leaf
        for(int i = 0 ; i < getNbBlocks() ; i++){
            blocks.push_back(&(getBlocks()[i]));
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