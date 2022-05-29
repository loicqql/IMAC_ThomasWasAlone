#include "Player.hpp"

using namespace std;

Player::Player() {
	pos = new Vector(0.0, 0.0);
	color = new Color(1.0, 1.0, 1.0);
	canJump = false;
	w = 7.0;
	h = 7.0;
	ax = 0.0;
	ay = 0.0;
	box = new Box(w, h, pos->getX(), pos->getY());
	deltaCamera = new Vector(0.0, 0.0);
}

void Player::setPos(Vector * vecPos) {
	pos = vecPos;
	box->setX(pos->getX());
	box->setY(pos->getY());
}

void Player::setPlayerNumber(int nb) {
	playerNumber = nb;
}

void Player::setShape(Vector * shape) {
	w = shape->getX();
    h = shape->getY();
	box->setW(shape->getX());
    box->setH(shape->getY());
}

Vector * Player::getShape() {
	return new Vector(w, h);
}

Vector * Player::getPos() {
	return pos;
}

void Player::setBlocks(vector <Block*> blks) {
	blocks = blks;
}

Box * Player::getBox() {
	return box;
}

void Player::setDelta(Vector * delta) {
	deltaCamera = delta;
}

void Player::setColor(Color * newColor) {
	color = newColor;
}

Color * Player::getColor() {
	return color;
}

void Player::render() {

	float hW = w / 2;
	float hH = h / 2;

	glColor3f(color->getR(), color->getG(), color->getB());
	glBegin(GL_POLYGON);
		glVertex2d((pos->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
		glVertex2d((pos->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
		glVertex2d((pos->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
		glVertex2d((pos->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
	glEnd();

}

void Player::drawTriangle() {
	float hW = 3 / 2;
	float hH = 2 / 2;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2d((pos->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() + hH - deltaCamera->getY() + (h / 2) + 2) / deltaCamera->getZ());
		glVertex2d((pos->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() - hH - deltaCamera->getY() + (h / 2) + 2) / deltaCamera->getZ());
		glVertex2d((pos->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() + hH - deltaCamera->getY() + (h / 2) + 2) / deltaCamera->getZ());
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

	ay -= 0.5; // gravity

	//CAP AX AY
	ax = ax > 3.0 ? 3.0 : ax;
	ax = ax < -3.0 ? -3.0 : ax;

	ay = ay > 5.0 ? 5.0 : ay;
	ay = ay < -5.0 ? -5.0 : ay;

	float reX = 0.0;
	float reY = 0.0;

	if(ax > 0) {
		reX = 3.0 / 100.0;
	}
	if(ax < 0) {
		reX = -3.0 / 100.0;
	}

	if(ay > 0) {
		reY = 5.0 / 100.0;
	}
	if(ay < 0) {
		reY = -5.0 / 100.0;
	}

	Vector d = Vector(ax, ay);
	pos->add(d);
	box->setX(pos->getX());
	box->setY(pos->getY());

	int k = 0;

	if(collision.testCollision(box, blocks, playerNumber)) {
		canJump = true;
	}

	while(collision.testCollision(box, blocks, playerNumber)) {
		ax = ax - reX;
		ay = ay - reY;
		pos->subtract(Vector(reX, reY));
		box->setX(pos->getX());
		box->setY(pos->getY());
		k++;
	}

	if(ax < 0.1 && ax > -0.1) {
		ax = 0.0;
	}
	if(ay < 0.1 && ay > -0.1) {
		ay = 0.0;
	}

	if(ax > 0) {
		if(ax > 0.5) {
			ax -= 0.5;
		}else {
			ax = 0.0;
		}
	}

	if(ax < 0) {
		if(ax < -0.5) {
			ax += 0.5;
		}else {
			ax = 0.0;
		}
	}
		

	// cout << "-----" << endl;
	// cout << ax << endl;
	// cout << ay << endl;
	// cout << "-----" << endl;

	// if(!collision.testCollision(box, blocks, playerNumber)) {
		
	// } else {
	// 	ay = 0.0;
	// }

	
	// if(ax > 0) {
	// 	ax -= 0.5;
	// }

	// if(ax < 0) {
	// 	ax += 0.5;
	// }


	// if(collision.testCollision(box, blocks, playerNumber)) {
	// 	pos->subtract(d);
	// }

	// if(collision.getCollision(box, blocks, playerNumber) == 'b') {
	// 	canJump = true;
	// }
}
