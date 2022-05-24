#include "Image.hpp"

using namespace std;

Image::Image() {
    surface = IMG_Load("images/logo_imac.png");

    if(surface) {
        loaded = true;
        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);

        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);

    } else {
        loaded = false;
    }


    


}

void Image::render() {
    if(loaded) {
        glBindTexture(GL_TEXTURE_2D, texture);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 1.0f);
                glTexCoord2f(1.0f, 0.0f); glVertex3f(32.0f, 0.0f, 1.0f);
                glTexCoord2f(1.0f, 1.0f); glVertex3f(32.0f, 32.0f, 1.0f);
                glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 32.0f, 1.0f);
            glEnd();
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}