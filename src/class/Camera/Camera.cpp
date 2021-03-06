#include "Camera.hpp"

using namespace std;

Camera::Camera() {
	zoom = 1.0;
    targetZoom = 1.0;
    delta = new Vector(0,0);
    delta->setZ(1.0);
}

void Camera::resetCamera() {
    delta->subtract(Vector(delta->getX(),delta->getY()));
}

Vector * Camera::getDelta() {
    return delta;
}

Vector * Camera::playerMove(Vector * vecPos) {

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

    testAreas(vecPos);

    return delta;
}

void Camera::addAreas(Area * area) { 
    areas.push_back(area);
}

void Camera::clearAreas() {
    areas.clear();
}

void Camera::testAreas(Vector * vecPos) {
    delta->setZ(1.0);
    targetZoom = 1.0;
    for(uint i = 0; i < areas.size(); ++i) {
        Area * area = areas[i];
        if(area->test(vecPos)) {
            targetZoom = area->getZoom();
        }
    }

    if(zoom < targetZoom) {
        zoom += 0.01; 
    }
    if(zoom > targetZoom) {
        zoom -= 0.01; 
    }

    delta->setZ(zoom);
}

void Camera::showArea() {
    for(uint i = 0; i < areas.size(); ++i) {
        Area * area = areas[i];

		float hW = area->getW() / 2;
		float hH = area->getH() / 2;
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINE_LOOP);
			glVertex2d((area->getX() + hW - delta->getX()) / delta->getZ(), (area->getY() + hH - delta->getY()) / delta->getZ());
			glVertex2d((area->getX() + hW - delta->getX()) / delta->getZ(), (area->getY() - hH - delta->getY()) / delta->getZ());
			glVertex2d((area->getX() - hW - delta->getX()) / delta->getZ(), (area->getY() - hH - delta->getY()) / delta->getZ());
			glVertex2d((area->getX() - hW - delta->getX()) / delta->getZ(), (area->getY() + hH - delta->getY()) / delta->getZ());
		glEnd();
	}
}
