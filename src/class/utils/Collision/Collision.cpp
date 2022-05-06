#include "Collision.hpp"

using namespace std;

Collision::Collision() {}

bool Collision::testCollision(Box * player, vector <Box*> boxs, int playerNumber) {

	for(int i = 0; i < boxs.size(); ++i) {
        Box * oneBox = boxs[i];
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

char Collision::getCollision(Box * player, vector <Box*> boxs, int playerNumber) {

    for(int i = 0; i < boxs.size(); ++i) {
        Box * oneBox = boxs[i];
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