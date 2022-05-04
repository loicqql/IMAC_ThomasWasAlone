#include "Player.hpp"

using namespace std;

Player::Player() {
	pos = new Vector(0.0, 0.0);
	color = new Color(1.0, 1.0, 1.0);
	box = new Box(5.0, 5.0, pos->getX(), pos->getY());
	w = 5.0;
	h = 5.0;
	ax = 0.0;
	ay = 0.0;
}

void Player::render() {
  float hW = w / 2;
  float hH = h / 2;

  glColor3f(color->getR(), color->getG(), color->getB());
  glBegin(GL_POLYGON);
      glVertex2d(pos->getX() + hW, pos->getY()  + hH);
      glVertex2d(pos->getX() + hW, pos->getY() - hH);
      glVertex2d(pos->getX()- hW, pos->getY()  - hH);
      glVertex2d(pos->getX()- hW, pos->getY() + hH);
  glEnd();
}

void Player::move(Vector *vecInput, Map *map) {

	ax = vecInput->getX() != 0 ? vecInput->getX() : ax;
	ay = vecInput->getY() != 0 ? vecInput->getY() : ay;

	if(!collision()) {
		ay -= 0.5;
	} else {
		ay = 0.0;
	}
	
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

	float hW = 100.0 / 2;
	float hH = 5.0 / 2;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2d(0.0 + hW, -50.0  + hH);
		glVertex2d(0.0 + hW, -50.0 - hH);
		glVertex2d(0.0 - hW, -50.0  - hH);
		glVertex2d(0.0 - hW, -50.0 + hH);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2d(0.0 + hW, 20.0  + hH);
		glVertex2d(0.0 + hW, 20.0 - hH);
		glVertex2d(0.0 - hW, 20.0  - hH);
		glVertex2d(0.0 - hW, 20.0 + hH);
	glEnd();

	Box * boxA[2];
	Box * box1 = new Box(100.0, 5.0, 0.0, -50.0);
	boxA[0] = box1;
	Box * box2 = new Box(100.0, 5.0, 0.0, 20.0);
	boxA[1] = box2;

	for (int i = 0; i < 2; i++) {
		Box * oneBox = boxA[i];

		if(box->getY() > oneBox->getY()) {
			if((box->getY() - box->getH() / 2) < (oneBox->getY() + oneBox->getH() / 2)) {
				return true;
			}
		}

		if(box->getX() > oneBox->getX()) {
			if((box->getX() - box->getW() / 2) < (oneBox->getX() + oneBox->getW() / 2)) {
				return true;
			}
		}

		if(box->getY() < oneBox->getY()) {
			if((box->getY() + box->getH() / 2) > (oneBox->getY() - oneBox->getH() / 2)) {
				return true;
			}
		}

		if(box->getX() < oneBox->getX()) {
			if((box->getX() + box->getW() / 2) > (oneBox->getX() - oneBox->getW() / 2)) {
				return true;
			}
		}
		
	}

	return false;
  
}

