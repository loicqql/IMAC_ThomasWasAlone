#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>

#include "class/Player/Player.hpp"
#include "class/Map/Map.hpp"
#include "class/utils/Vector/Vector.hpp"

Player player;
Map *map = new Map();
Vector * vecInput;

/* Dimensions initiales et titre de la fenetre */
static const unsigned int WINDOW_WIDTH = 800;
static const unsigned int WINDOW_HEIGHT = 600;
static const char WINDOW_TITLE[] = "Game";

/* Espace fenetre virtuelle */
static const float GL_VIEW_SIZE = 150.;

/* Subdivisions cercle */
static const int CIRCLE_SUBDIVS = 2<<5;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


void onWindowResized(unsigned int width, unsigned int height) { 
    float aspectRatio = width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if( aspectRatio > 1) {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2. * aspectRatio, GL_VIEW_SIZE / 2. * aspectRatio, 
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.);
    }
    else {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.,
        -GL_VIEW_SIZE / 2. / aspectRatio, GL_VIEW_SIZE / 2. / aspectRatio);
    }
}


int main(int argc, char** argv) {
    //* Initialisation de la SDL */

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {

        const char* error = SDL_GetError();
        fprintf(
            stderr, 
            "Erreur lors de l'intialisation de la SDL : %s\n", error);

        SDL_Quit();
        return EXIT_FAILURE;
    }
	
    /* Ouverture d'une fenetre et creation d'un contexte OpenGL */

    SDL_Window* window;
    {
        window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

        if(NULL == window) 
        {
            const char* error = SDL_GetError();
            fprintf(
                stderr,
                "Erreur lors de la creation de la fenetre : %s\n", error);

            SDL_Quit();
            return EXIT_FAILURE;
        }
    }
    
    SDL_GLContext context;
    {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        context = SDL_GL_CreateContext(window);
    
        if(NULL == context) {
            const char* error = SDL_GetError();
            fprintf(
                stderr,
                "Erreur lors de la creation du contexte OpenGL : %s\n", error);

            SDL_DestroyWindow(window);
            SDL_Quit();
            return EXIT_FAILURE;
        }
    }    
  
    onWindowResized(WINDOW_WIDTH, WINDOW_HEIGHT);

    vecInput = new Vector(0.0, 0.0);
  
    /* Boucle principale */
    int loop = 1;
    while(loop) {
        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /* Placer ici le code de dessin */
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        /* le vrai main */
        player.move(vecInput, map);
        player.render();

        vecInput = nullptr;

        /* Echange du front et du back buffer : mise a jour de la fenetre */
        SDL_GL_SwapWindow(window);
        
        /* Boucle traitant les evenements */
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            /* L'utilisateur ferme la fenetre : */
			if(e.type == SDL_QUIT) {
				loop = 0;
				break;
			}
		
			if(	e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE)) {
				loop = 0; 
				break;
			}
            
            switch(e.type) {
                case SDL_WINDOWEVENT:
                    switch (e.window.event) {
                        /* Redimensionnement fenetre */
                        case SDL_WINDOWEVENT_RESIZED:
                            onWindowResized(e.window.data1, e.window.data2);                
                            break;

                        default:
                            break; 
                    }
                    break;

                /* Clic souris */
                case SDL_MOUSEBUTTONUP:
                    //vecInput = new Vector(0.0, 10.0);
                    break;
                
                /* Touche clavier
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_q) {
                        vecInput = new Vector(-10.0, 0.0);
                    }
                    if(e.key.keysym.sym == SDLK_d) {
                        vecInput = new Vector(10.0, 0.0);
                    }
                    if(e.key.keysym.sym == SDLK_z) {
                        vecInput = new Vector(0.0, 10.0);
                    }
                    break;
                    
                default:
                    break;
                     */
            }
        }

        const Uint8* keystates = SDL_GetKeyboardState(NULL);
        if(keystates[SDL_SCANCODE_LEFT]) {
            vecInput = new Vector(-5.0, 0.0);
        }
        if(keystates[SDL_SCANCODE_RIGHT]) {
            vecInput = new Vector(5.0, 0.0);
        }
        if(keystates[SDL_SCANCODE_SPACE]) {
            vecInput = new Vector(0.0, 5.0);
        }

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        /* Si trop peu de temps s'est ecoule, on met en pause le programme */
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }

        if(vecInput == nullptr) {
            vecInput = new Vector(0.0, 0.0);
        }
    }

    /* Liberation des ressources associees a la SDL */ 
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
