#include "Draw.hpp"

using namespace std;

Draw::Draw() {}

void Draw::setDelta(Vector * delta) {
	deltaCamera = delta;
}

void Draw::render(vector <Block*> blocks, int nbPlayers) {
    for(int i = nbPlayers; i < blocks.size(); ++i) {
        Block * block = blocks[i];
        Box * oneBox = block->getBox();

		float hW = oneBox->getW() / 2;
		float hH = oneBox->getH() / 2;
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex2d((oneBox->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (oneBox->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
			glVertex2d((oneBox->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (oneBox->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
			glVertex2d((oneBox->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (oneBox->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
			glVertex2d((oneBox->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (oneBox->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
		glEnd();
	}
}

void Draw::render(Block * block) {
    Box * oneBox = block->getBox();
    float hW = oneBox->getW() / 2;
    float hH = oneBox->getH() / 2;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2d((oneBox->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (oneBox->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
        glVertex2d((oneBox->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (oneBox->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
        glVertex2d((oneBox->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (oneBox->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
		glVertex2d((oneBox->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (oneBox->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
    glEnd();
}