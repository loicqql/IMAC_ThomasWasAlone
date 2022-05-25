#include "Gui.hpp"

using namespace std;

Gui::Gui() {

    setUpAreasStart();
}

void Gui::setUpAreasStart() { 

    areas.clear();
    Area * area1 = new Area(100.0, 100.0, 0, 0, 1.0);
    areas.push_back(area1);
}

void Gui::setUpAreasPause() { 

    areas.clear();
    Area * area1 = new Area(100.0, 50.0, 0, 0, 1.0);
    areas.push_back(area1);
}

void Gui::clearArea() {
    areas.clear();
}

bool Gui::testAreas(Vector * vecClick) {
    for(int i = 0; i < areas.size(); ++i) {
        Area * area = areas[i];
        float hW = area->getW() / 2;
		float hH = area->getH() / 2;
        if((vecClick->getX() > area->getX() - hW) && (vecClick->getX() < area->getX() + hW)) {
            if((vecClick->getY() > area->getY() - hH) && (vecClick->getY() < area->getX() + hH)) {
                return true;
            }
        }
    }
    return false;
}

void Gui::showArea() {
    for(int i = 0; i < areas.size(); ++i) {
        Area * area = areas[i];

		float hW = area->getW() / 2;
		float hH = area->getH() / 2;
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINE_LOOP);
			glVertex2d((area->getX() + hW), (area->getY() + hH));
			glVertex2d((area->getX() + hW), (area->getY() - hH));
			glVertex2d((area->getX() - hW), (area->getY() - hH));
			glVertex2d((area->getX() - hW), (area->getY() + hH));
		glEnd();
	}
}
