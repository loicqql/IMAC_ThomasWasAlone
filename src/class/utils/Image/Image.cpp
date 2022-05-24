#include "Image.hpp"

using namespace std;

Image::Image() {}

void Image::push(GLuint * ytextures) {
    textures = ytextures;
}

void Image::setDelta(Vector * delta) {
    deltaCamera = delta;
    
}

void Image::render(int index) {
    glBindTexture(GL_TEXTURE_2D, textures[index]);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f); glVertex2f((0.0f - deltaCamera->getX()) / deltaCamera->getZ(), (0.0f - deltaCamera->getY()) / deltaCamera->getZ());
            glTexCoord2f(1.0f, 0.0f); glVertex2f((32.0f - deltaCamera->getX()) / deltaCamera->getZ(), (0.0f - deltaCamera->getY()) / deltaCamera->getZ());
            glTexCoord2f(1.0f, 1.0f); glVertex2f((32.0f - deltaCamera->getX()) / deltaCamera->getZ(), (32.0f - deltaCamera->getY()) / deltaCamera->getZ());
            glTexCoord2f(0.0f, 1.0f); glVertex2f((0.0f - deltaCamera->getX()) / deltaCamera->getZ(), (32.0f - deltaCamera->getY()) / deltaCamera->getZ());
        glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}