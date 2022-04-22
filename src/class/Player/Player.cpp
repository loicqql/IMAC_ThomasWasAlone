#include "Player.hpp"

using namespace std;

Player::Player() {
  pos = new Vector(0.0, 0.0);
  dim = new Vector(50.0, 50.0);
  color = new Color(1.0, 1.0, 1.0);
}

void Player::render() {
    float hX = dim->getX() / 2;
    float hY = dim->getY() / 2;

    glColor3f(color->getR(), color->getG(), color->getB());
    glBegin(GL_POLYGON);
        glVertex2d(pos->getX() + hX, pos->getY()  + hY);
        glVertex2d(pos->getX() + hX, pos->getY() - hY);
        glVertex2d(pos->getX()- hX, pos->getY()  - hY);
        glVertex2d(pos->getX()- hX, pos->getY() + hY);
    glEnd();
    
}

