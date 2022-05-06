#include "Draw.hpp"

using namespace std;

Draw::Draw() {}

void Draw::setDelta(Vector * delta) {
	deltaCamera = delta;
}

void Draw::render(vector <Box*> boxs) {
    for(int i = 4; i < boxs.size(); ++i) {
        Box * oneBox = boxs[i];
		float hW = oneBox->getW() / 2;
		float hH = oneBox->getH() / 2;
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex2d(oneBox->getX() + hW - deltaCamera->getX(), oneBox->getY() + hH - deltaCamera->getY());
			glVertex2d(oneBox->getX() + hW - deltaCamera->getX(), oneBox->getY() - hH - deltaCamera->getY());
			glVertex2d(oneBox->getX() - hW - deltaCamera->getX(), oneBox->getY() - hH - deltaCamera->getY());
			glVertex2d(oneBox->getX() - hW - deltaCamera->getX(), oneBox->getY() + hH - deltaCamera->getY());
		glEnd();
	}
}

void Draw::render(Box * oneBox) {
    float hW = oneBox->getW() / 2;
    float hH = oneBox->getH() / 2;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2d(oneBox->getX() + hW - deltaCamera->getX(), oneBox->getY() + hH - deltaCamera->getY());
        glVertex2d(oneBox->getX() + hW - deltaCamera->getX(), oneBox->getY() - hH - deltaCamera->getY());
        glVertex2d(oneBox->getX() - hW - deltaCamera->getX(), oneBox->getY() - hH - deltaCamera->getY());
        glVertex2d(oneBox->getX() - hW - deltaCamera->getX(), oneBox->getY() + hH - deltaCamera->getY());
    glEnd();
}