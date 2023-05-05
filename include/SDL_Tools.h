#ifndef SDLTOOLS_H
#define SDLTOOLS_H
//SDL lib

#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fullInit(SDL_Window **window, SDL_Renderer **renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);

int initTexture(SDL_Renderer *renderer, SDL_Texture *texture, int w, int h);

SDL_Texture* loadImage(const char path[], SDL_Renderer *renderer);

int drawImage(SDL_Texture *image_texture, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *rectCut, SDL_Rect *rectPos, int angle, const SDL_RendererFlip flip);
// SDL_FLIP_NONE pour ne pas avoir de rotation et angle 0

int texturePaste(SDL_Renderer *renderer, SDL_Texture *texture_cible, SDL_Texture *texture_tmp);

#endif