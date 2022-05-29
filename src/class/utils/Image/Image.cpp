#include "Image.hpp"

using namespace std;

Image::Image() {}

void Image::push(GLuint * ytextures) {
    textures = ytextures;
}

void Image::setDelta(Vector * delta) {
    deltaCamera = delta;
    
}

void Image::render(int index, Vector * shape, Vector * pos, bool camera) {
    if(camera) {
        glBindTexture(GL_TEXTURE_2D, textures[index]);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex2f((pos->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() - deltaCamera->getY()) / deltaCamera->getZ());
                glTexCoord2f(1.0f, 0.0f);
                glVertex2f((pos->getX() + shape->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() - deltaCamera->getY()) / deltaCamera->getZ());
                glTexCoord2f(1.0f, shape->getY() / shape->getX());
                glVertex2f((pos->getX() + shape->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() + shape->getY() - deltaCamera->getY()) / deltaCamera->getZ());
                glTexCoord2f(0.0f, shape->getY() / shape->getX());
                glVertex2f((pos->getX() - deltaCamera->getX()) / deltaCamera->getZ(), (pos->getY() + shape->getY() - deltaCamera->getY()) / deltaCamera->getZ());
            glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
    }else {
        glBindTexture(GL_TEXTURE_2D, textures[index]);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f);
                glVertex2f(pos->getX(), pos->getY());
                glTexCoord2f(1.0f, 0.0f);
                glVertex2f(pos->getX() + shape->getX(), pos->getY());
                glTexCoord2f(1.0f, shape->getX() / shape->getY());
                glVertex2f(pos->getX() + shape->getX(), pos->getY() + shape->getY());
                glTexCoord2f(0.0f, shape->getX() / shape->getY());
                glVertex2f(pos->getX(), pos->getY() + shape->getY());
            glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
}