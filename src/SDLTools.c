#include "SDL_Tools.h"



int fullInit(SDL_Window **window, SDL_Renderer **renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
    if(0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1; 
    }
    if(0 != SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, window, renderer)){
        fprintf(stderr,"Erreur SDL_CreateWindowAndRenderer : %s",SDL_GetError());
        return -1; 
    }
    return 0; 
}


int initTexture(SDL_Renderer *renderer, SDL_Texture *texture, int w, int h) {  
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
    if(NULL == texture){
        fprintf(stderr, "ERREUR SDL_CreateTexture: %s\n", SDL_GetError());
        return -1;
    }
    return 0;
}


SDL_Texture* loadImage(const char path[], SDL_Renderer *renderer) {
    SDL_Texture* texture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path); // On utilise ici la fonction IMG_Load de SDL_image.
    if (loadedSurface == NULL) {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
    }
    else {
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    }
    return texture;
}

int drawImage(SDL_Texture *image_texture, SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect *rectCut, SDL_Rect *rectPos, int angle, const SDL_RendererFlip flip) { 
    SDL_SetRenderTarget(renderer, texture);
    SDL_RenderCopyEx(renderer, image_texture, rectCut, rectPos, angle, NULL, flip);
    SDL_SetRenderTarget(renderer, NULL);
    return 0;
}

