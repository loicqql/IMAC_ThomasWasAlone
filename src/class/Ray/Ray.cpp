#include "Ray.hpp"

using namespace std;

Ray::Ray() {
    k=0;
}

bool sortVectorCCW(Vector * v1, Vector * v2) {
    float av1 = atan2f(v1->getY() - 0.0, v1->getX() - 50.0);
    float av2 = atan2f(v2->getY() - 0.0, v2->getX() - 50.0);
    return av1 < av2;
}

bool sortVector(Vector * v1, Vector * v2) {
    if(v1->getAngle() > v2->getAngle()) {
        return true;
    }
    return false;
}

void Ray::setDelta(Vector * delta) {
    deltaCamera = delta; 
}

void Ray::render() {

    vec = new Vector(0.0, 50.0);

    float hW = 4.0 / 2;
    float hH = 4.0 / 2;
    glColor3f(255 / 44.0, 255 / 55.0, 255 / 101.0);
    glBegin(GL_POLYGON);
        glVertex2d((vec->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
        glVertex2d((vec->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
        glVertex2d((vec->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
		glVertex2d((vec->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
    glEnd();

    vector <Vector*> corners;

    //GET ALL CORNERS
    float W;
    float H;
    for(int i = 0; i < blocks.size(); ++i) {
        Block * block = blocks[i];
        Box * oneBox = block->getBox();
        W = oneBox->getW() / 2 - 0.15;
        H = oneBox->getH() / 2 - 0.15;
        corners.push_back(new Vector(oneBox->getX() + W, oneBox->getY() + H));
        corners.push_back(new Vector(oneBox->getX() + W, oneBox->getY() - H));
        corners.push_back(new Vector(oneBox->getX() - W, oneBox->getY() + H));
        corners.push_back(new Vector(oneBox->getX() - W, oneBox->getY() - H));

        W = oneBox->getW() / 2;
        H = oneBox->getH() / 2;

        // corners.push_back(new Vector(oneBox->getX() + W, oneBox->getY() + H));
        // corners.push_back(new Vector(oneBox->getX() + W, oneBox->getY() - H));
        // corners.push_back(new Vector(oneBox->getX() - W, oneBox->getY() + H));
        // corners.push_back(new Vector(oneBox->getX() - W, oneBox->getY() - H));
    }

    //TEST DRAW
    // for(int i = 0; i < corners.size(); ++i) {
    //     float hW = 4.0 / 2;
    //         float hH = 4.0 / 2;
    //         glColor3f(255 / 44.0, 255 / 55.0, 255 / 101.0);
    //         glBegin(GL_POLYGON);
    //         glVertex2d((corners[i]->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (corners[i]->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
    //         glVertex2d((corners[i]->getX() + hW - deltaCamera->getX()) / deltaCamera->getZ(), (corners[i]->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
    //         glVertex2d((corners[i]->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (corners[i]->getY() - hH - deltaCamera->getY()) / deltaCamera->getZ());
    //         glVertex2d((corners[i]->getX() - hW - deltaCamera->getX()) / deltaCamera->getZ(), (corners[i]->getY() + hH - deltaCamera->getY()) / deltaCamera->getZ());
    //     glEnd();
    // }

    vector <Vector*> intersects;

    //CAST RAYS IN CORNERS
    for(int i = 0; i < corners.size(); ++i)  {
        double angle = atan2f(corners[i]->getY() - vec->getY(), corners[i]->getX() - vec->getX());
        for (int j = 0; j < 1500; j++) {
            vec->add(Vector(0.5 * cos(angle), (0.5 * sin(angle))));
            if(collision.rayIntersection(blocks, vec)) {
                Vector * n = new Vector(vec->getX(), vec->getY());
                n->setAngle(angle);
                intersects.push_back(n);
                break;
            }
        }
        vec = new Vector(0.0, 50.0);
    }

    //sort array
    sort(intersects.begin(), intersects.end(), sortVector);
    // sort(intersects.begin(), intersects.end(), sortVector);

    

    glColor4f(44.0 / 255.0, 55.0 / 255.0, 101.0 / 255.0, 0.5);
    glBegin(GL_POLYGON);
    // glBegin(GL_LINES);
    // glVertex2d((-100 - deltaCamera->getX()) / deltaCamera->getZ(), (50 - deltaCamera->getY()) / deltaCamera->getZ());
    // glVertex2d((100 - deltaCamera->getX()) / deltaCamera->getZ(), (50 - deltaCamera->getY()) / deltaCamera->getZ());

    cout << "-1-" << endl;

    for(int i = 0; i < intersects.size(); ++i) {
        Vector * intersect = intersects[i];

            cout << intersect->getX() << endl;
        
            // glVertex2d((vec->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (vec->getY() - deltaCamera->getY()) / deltaCamera->getZ());
            glVertex2d((intersect->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (intersect->getY() - deltaCamera->getY()) / deltaCamera->getZ());
        
    }
    
    glEnd();

//    test(intersects[k]);

//    k++;

//    if(k >= intersects.size()) {
//        k=0;
//    }

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
