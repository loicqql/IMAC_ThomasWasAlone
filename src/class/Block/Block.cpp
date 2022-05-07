#include "Block.hpp"

using namespace std;

Block::Block(Box * aBox) {
    box = aBox;
    steps = 100.0;
}

Box * Block::getBox() {
    return box;
}

void Block::setPosA(Vector * pos) {
    posA = pos;
}

void Block::setPosB(Vector * pos) {
    posB = pos;
}

void Block::setSteps(float nb) {
    steps = nb;
}

void Block::updateMovement() {
    if(posA != nullptr && posB != nullptr) {
        if((box->getX() >= posA->getX() && box->getX() <= posB->getX()) || (box->getX() <= posA->getX() && box->getX() >= posB->getX())) {
            float dX = (posA->getX() - posB->getX()) / steps;
            float dY = (posA->getY() - posB->getY()) / steps;
            box->setX(box->getX() - dX);
            box->setY(box->getY() - dY);
        }else {
            posB =  posA;
            posA = new Vector(box->getX(), box->getY());
        }
    }
}
