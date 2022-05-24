#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class Image {
	public:
        Image();

        void render();

		
	private:
        bool loaded;
        SDL_Surface* surface;
        GLuint texture;
};