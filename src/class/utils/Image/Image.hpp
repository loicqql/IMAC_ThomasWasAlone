#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#if defined(__APPLE__)
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif
#include <vector>
#include "../Vector/Vector.hpp"

#include <iostream>

using namespace std;

class Image {
	public:
        Image();

        void render(int index);
		void setDelta(Vector * delta);
        void push(GLuint * ytextures);
		GLuint * getTextures();
		
	private:
        GLuint * textures;
		Vector * deltaCamera;
};