#include "Camera.hpp"

using namespace std;

Camera::Camera() {
	zoom = 1.0;
    delta = new Vector(0,0);
}

Vector * Camera::getDelta() {
    return delta;
}

Vector * Camera::playerMove(Vector * vecPos) {

    //x1
    if(vecPos->getX() - delta->getX() > MaxX) {
        delta->add(Vector(((vecPos->getX() - delta->getX()) - MaxX) / (MaxX/2), 0.0));
    }
    if(vecPos->getX() - delta->getX() < MinX) {
        delta->add(Vector((MinX - (vecPos->getX() - delta->getX())) / (MinX/2), 0.0));
    }
    if(vecPos->getY() - delta->getY() > MaxY) {
        delta->add(Vector(0.0, ((vecPos->getY() - delta->getY()) - MaxY) / (MaxY/2)));
    }
    if(vecPos->getY() - delta->getY() < MinY) {
        delta->add(Vector(0.0, (MinY - (vecPos->getY() - delta->getY())) / (MinY/2)));
    }

    return delta;
}
