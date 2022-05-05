#include "Player.hpp"

using namespace std;

Player::Player() {
	pos = new Vector(0.0, 0.0);
	color = new Color(1.0, 1.0, 1.0);
	box = new Box(5.0, 5.0, pos->getX(), pos->getY());
	canJump = false;
	w = 5.0;
	h = 5.0;
	ax = 0.0;
	ay = 0.0;
	deltaCamera = new Vector(0.0, 0.0);
}

Vector * Player::getPos() {
	return pos;
}

void Player::setDelta(Vector * delta) {
	deltaCamera = delta;
}

void Player::setColor(Color * newColor) {
	color = newColor;
}

void Player::render() {

	float hW = w / 2;
	float hH = h / 2;

	glColor3f(color->getR(), color->getG(), color->getB());
	glBegin(GL_POLYGON);
		glVertex2d(pos->getX() + hW - deltaCamera->getX(),  pos->getY() + hH - deltaCamera->getY());
		glVertex2d(pos->getX() + hW - deltaCamera->getX(),  pos->getY() - hH - deltaCamera->getY());
		glVertex2d(pos->getX() - hW - deltaCamera->getX(),  pos->getY() - hH - deltaCamera->getY());
		glVertex2d(pos->getX() - hW - deltaCamera->getX(),  pos->getY() + hH - deltaCamera->getY());
	glEnd();

	//RENDER BOX TEMP

	Box * box1 = new Box(2000.0, 5.0, 0.0 - deltaCamera->getX(), (-50.0) - deltaCamera->getY());
	Box * box2 = new Box(50.0, 50.0, (-30.0) - deltaCamera->getX(), (-20.0) - deltaCamera->getY());

	Box * boxA[2];
	boxA[0] = box1;
	boxA[1] = box2;

	for (int i = 0; i < 2; i++) {
		Box * oneBox = boxA[0];

		hW = oneBox->getW() / 2;
		hH = oneBox->getH() / 2;
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex2d(oneBox->getX() + hW, oneBox->getY() + hH);
			glVertex2d(oneBox->getX() + hW, oneBox->getY() - hH);
			glVertex2d(oneBox->getX() - hW, oneBox->getY() - hH);
			glVertex2d(oneBox->getX() - hW, oneBox->getY() + hH);
		glEnd();

	}
}

void Player::drawTriangle() {
	float hW = 3 / 2;
	float hH = 2 / 2;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2d(pos->getX() + hW - deltaCamera->getX(), 	pos->getY() + hH - deltaCamera->getY() + (h / 2) + 2);
		glVertex2d(pos->getX() - deltaCamera->getX(),  pos->getY() - hH - deltaCamera->getY() + (h / 2) + 2);
		glVertex2d(pos->getX() - hW - deltaCamera->getX(),  pos->getY() + hH - deltaCamera->getY() + (h / 2) + 2);
	glEnd();
}

void Player::move(Vector *vecInput) {	

	ax = vecInput->getX() != 0 ? vecInput->getX() : ax;

	if(canJump) {
		ay = vecInput->getY() != 0 ? vecInput->getY() : ay;
		if(vecInput->getY() != 0) {
			canJump = false;
		}
	}

	if(!collision()) {
		ay -= 0.5;
	} else {
		ay = 0.0;
	}

	// cout << col << endl;
	
	if(ax > 0) {
		ax -= 0.5;
	}

	if(ax < 0) {
		ax += 0.5;
	}

	Vector d = Vector(ax, ay);

	pos->add(d);

	box->setX(pos->getX());
	box->setY(pos->getY());

	/*cout << "-----" << endl;
	cout << ax << endl;
	cout << ay << endl;
	cout << "-----" << endl;*/

	if(collision()) {
		pos->subtract(d);
	}
}

bool Player::collision() {

	//get from map
	Box * box1 = new Box(2000.0, 5.0, 0.0, (-50.0));
	Box * box2 = new Box(50.0, 50.0, (-30.0), (-20.0));
	
	Box * boxA[2];
	boxA[0] = box1;
	boxA[1] = box2;

	for (int i = 0; i < 2; i++) {
		Box * oneBox = boxA[0];

		col = getCollision(box, oneBox);
		if(col == 'b') {
			canJump = true;
		}

		if(!(
		(box->getX() - (box->getW() / 2) >= oneBox->getX() + (oneBox->getW() / 2)) || //test droite
		(box->getX() + (box->getW() / 2) <= oneBox->getX() - (oneBox->getW() / 2)) || //test gauche
		(box->getY() - (box->getH() / 2) >= oneBox->getY() + (oneBox->getH() / 2)) || //test haut
		(box->getY() + (box->getH() / 2) <= oneBox->getY() - (oneBox->getH() / 2))    //test bas
		)) {
			return true;
		}
	}

	return false;	
  
}

char Player::getCollision(Box * player, Box * box) {
	if(player->getX() - (player->getW() / 2) == box->getX() + (box->getW() / 2)) {
		return 'l';
	}
	if(player->getX() + (player->getW() / 2) == box->getX() - (box->getW() / 2)) {
		return 'r';
	}
	if(player->getY() - (player->getH() / 2) == box->getY() + (box->getH() / 2)) {
		return 'b';
	}
	if(player->getY() + (player->getH() / 2) == box->getY() - (box->getH() / 2)) {
		return 't';
	}
	return '#';
}
