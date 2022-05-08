#include "Ray.hpp"

using namespace std;

Ray::Ray() {}

void Ray::setDelta(Vector * delta) {
    deltaCamera = delta; 
}

void Ray::render() {

    vec = new Vector(0.0, 50.0);

    // float hW = 4.0 / 2;
    // float hH = 4.0 / 2;
    // glColor3f(255 / 44.0, 255 / 55.0, 255 / 101.0);
    // glBegin(GL_POLYGON);
    //     glVertex2d((vec->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
    //     glVertex2d((vec->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
    //     glVertex2d((vec->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
	// 	glVertex2d((vec->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
    // glEnd();

    glColor3f(44.0 / 255.0, 55.0 / 255.0, 101.0 / 255.0);
    // glBegin(GL_QUAD_STRIP);
    glBegin(GL_LINES);

    // glVertex2d((-1500.0 - deltaCamera->getX()) / deltaCamera->getZ(), (50.0 - deltaCamera->getY()) / deltaCamera->getZ());
    // glVertex2d((-1500.0 - deltaCamera->getX()) / deltaCamera->getZ(), (-50.0 - deltaCamera->getY()) / deltaCamera->getZ());

    for (float i = M_PI; i < M_PI * 2.0; i += 0.005) {
        for (int j = 0; j < 500; j++) {
            vec->add(Vector(1.0 * cos(i), (1.0 * sin(i))));
            if(collision.rayIntersection(blocks, vec)) {
                // test(vec);
                // glVertex2d((vec->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() - deltaCamera->getY()) / deltaCamera->getZ());
                break;
            }
        }
        glVertex2d((vec->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() - deltaCamera->getY()) / deltaCamera->getZ());
        vec = new Vector(0.0, 50.0);
        glVertex2d((vec->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() - deltaCamera->getY()) / deltaCamera->getZ());
    }

    // glVertex2d((1500.0 - deltaCamera->getX()) / deltaCamera->getZ(), (-50.0 - deltaCamera->getY()) / deltaCamera->getZ());
    // glVertex2d((1500.0 - deltaCamera->getX()) / deltaCamera->getZ(), (50.0 - deltaCamera->getY()) / deltaCamera->getZ());

    glEnd();

}

void Ray::test(Vector * vec) {
    float hW = 2.0 / 2;
    float hH = 2.0 / 2;
    glColor3f(255 / 44.0, 255 / 55.0, 255 / 101.0);
    glBegin(GL_POLYGON);
        glVertex2d(((vec->getX() + hW) - deltaCamera->getX()) / deltaCamera->getZ(), ((vec->getY() + hH) - deltaCamera->getY()) / deltaCamera->getZ());
        glVertex2d(((vec->getX() + hW) - deltaCamera->getX()) / deltaCamera->getZ(), ((vec->getY() - hH) - deltaCamera->getY()) / deltaCamera->getZ());
        glVertex2d(((vec->getX() - hW) - deltaCamera->getX()) / deltaCamera->getZ(), ((vec->getY() - hH) - deltaCamera->getY()) / deltaCamera->getZ());
		glVertex2d(((vec->getX() - hW) - deltaCamera->getX()) / deltaCamera->getZ(), ((vec->getY() + hH) - deltaCamera->getY()) / deltaCamera->getZ());

        // glVertex2d(vec->getX() + hW, vec->getY() + hH);
        // glVertex2d(vec->getX() + hW, vec->getY() - hH);
        // glVertex2d(vec->getX() - hW, vec->getY() - hH);
		// glVertex2d(vec->getX() - hW, vec->getY() + hH);
    glEnd();
}

void Ray::setBlocks(vector <Block*> blks) {
    blocks = blks;
}
