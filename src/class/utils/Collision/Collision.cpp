#include "Collision.hpp"

using namespace std;

Collision::Collision() {}

bool Collision::testCollision(Box * player, vector <Block*> blocks, int playerNumber) {

	for(int i = 0; i < blocks.size(); ++i) {
        Block * block = blocks[i];
        Box * oneBox = block->getBox();
        
        if(i != playerNumber) { // not test collision itself
            // col = getCollision(box, oneBox);
            // if(col == 'b') {
            // 	canJump = true;
            // }

            if(!(
            (player->getX() - (player->getW() / 2) >= oneBox->getX() + (oneBox->getW() / 2)) || //test droite
            (player->getX() + (player->getW() / 2) <= oneBox->getX() - (oneBox->getW() / 2)) || //test gauche
            (player->getY() - (player->getH() / 2) >= oneBox->getY() + (oneBox->getH() / 2)) || //test haut
            (player->getY() + (player->getH() / 2) <= oneBox->getY() - (oneBox->getH() / 2))    //test bas
            )) {
                return true;
            }
        }
	}

	return false;	
  
}

char Collision::getCollision(Box * player, vector <Block*> blocks, int playerNumber) {


    for(int i = 0; i < blocks.size(); ++i) {
        Block * block = blocks[i];
        Box * oneBox = block->getBox();

        if(i != playerNumber) { // not test collision itself

            if(player->getX() - (player->getW() / 2) == oneBox->getX() + (oneBox->getW() / 2)) {
                return 'l';
            }
            if(player->getX() + (player->getW() / 2) == oneBox->getX() - (oneBox->getW() / 2)) {
                return 'r';
            }
            if(player->getY() - (player->getH() / 2) == oneBox->getY() + (oneBox->getH() / 2)) {
                return 'b';
            }
            if(player->getY() + (player->getH() / 2) == oneBox->getY() - (oneBox->getH() / 2)) {
                return 't';
            }
        }
    }
	
	return '#';
}

bool Collision::rayIntersection(vector <Block*> blocks, Vector * vec) {

    for(int i = 0; i < blocks.size(); ++i) {
        Block * block = blocks[i];
        Box * oneBox = block->getBox();

        float hW = oneBox->getW() / 2;
		float hH = oneBox->getH() / 2;
        if((vec->getX() > oneBox->getX() - hW) && (vec->getX() < oneBox->getX() + hW)) {
            if((vec->getY() > oneBox->getY() - hH) && (vec->getY() < oneBox->getY() + hH)) {
                return true;
            }
        }
        
    }
	
	return false;
}