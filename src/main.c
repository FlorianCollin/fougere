/*
COLLIN FLORIAN E1 ENSEIRB

POJET C

Ce programme ce trouve dans le cadre d'un projet scolaire en 1er année d'Électronique à l'ENSEIRB MATMECA.
L'objectif finale de ce projet et de réaliser une fractale / image de fougère au format .bmp


ATTENTION               README !!

Si vous voulez visualiser la fractale en rosase avec les différentes options alors il faut avoir installer SDL2 et SDL_image sur votre machine.
Voir le Makefile !!

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define SDL_VISU //option pour avoir une visualisation graphique et intéractive de la fractale
#define ROTATE // option pour afficher la rotation de la rosase
// #define MOVE // option pour ajouter le mouvement de la rosase
// #define GAME // active certain paramètre qui permete de faire un futur jeu ou il faut eviter la rosase



#ifdef SDL_VISU
#include <SDL2/SDL.h>s
#include <SDL2/SDL_image.h>
#include "SDL_Tools.h"
// faire les definitions des variables ici
#endif



// Les fonctions et les macros sont inclus grace au fichier ci dessous.
#include "bmpTools.h"
#include "mathTools.h"
#include "macro.h"
#include "foug.h"
#include "listChaine.h"




int main() {

    #ifdef SDL_VISU

    // Initialisation de SDL2

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;

    if (fullInit(&window, &renderer, WIDTH, HEIGHT)) {
        printf("Erreur lors de l'initialisation de SDL\n");      
        SDL_Quit();
        return 1;
    }
    
    #endif

    // COLOR 
    //const COLOR black = {0, 0, 0};
    const COLOR white = {255,255,255};

    P_D O;
    O.x = 10.0 * UP_SCALE_FACTOR;
    O.y = 424 * UP_SCALE_FACTOR;

    // La première phase du projet conciste à réaliser la figure géométrique et les 3 sous figure

    // Petit test pour voir si tout est OK!
    printf("hello world\n"); // toujours dire bonjour !
    info();

    // On definit les coordonnées exacts de tout les premiers points

    // J'ai defini la fonction init_point (voir "mathTools.c"),
    //qui me permet de determiner les coordonnées d'un point connaisant une origine, une distance et un angle.

    P_D H = init_point(OH, 0.0, O);
    P_D A = init_point(OA, HOA, O);
    P_D B = init_point(OB, HOB, O);
    P_D C = init_point(OC, HOC, O);
    P_D D = init_point(OD, HOD, O);
    P_D E = init_point(OE, HOE, O);
    
    affiche_point_d(O);
    affiche_point_d(A);
    affiche_point_d(B);
    affiche_point_d(C);
    affiche_point_d(D);
    affiche_point_d(E);
    printf("init finish\n");

    PIC pic  = new_pic(WIDTH, HEIGHT);
    set_all_pix(pic, white);

 
    ////////////  ETAPE 1 : TEST  ////////////
    // premier test de draw_line
    // P_D P1 = {0,0};
    // P_D P2 = {50,20};
    // draw_line(pic, black, A, B);
    // // manipulation du pic
    // draw_line(pic, gris, O, H);
    // trace_figure_initial(pic, gris, O, A, B, C, D, E); // on trace la première figure
    // set_pixV2(pic, red, O);
    // set_pixV2(pic, red, H);
    // set_pixV2(pic, red, A);
    // set_pixV2(pic, red, B);
    // set_pixV2(pic, red, C);
    // set_pixV2(pic, red, D);
    // set_pixV2(pic, red, E);
    // Premier test de création des 3 sous figure à la main
    // Par la suite on passera bien sur par une fonction recurssive
    // P_D Og = init_point(OOg*OH, 0, O);  //<-- ici c simple car l'angle vaut 0,
    // // mais au bout de plusieur ittération plus dutou haha ;)
    // P_D Hg = init_point(OgHg*OH, HOgHg, Og);
    // P_D Or = init_point(OOr*OH, 0, O);
    // P_D Hr = init_point(OrHr*OH, HOrHr, Or);
    // P_D Ob = init_point(OOb*OH, 0, O);
    // P_D Hb = init_point(ObHb*OH, HObHb, Ob);
    // // printf("Or : \n");
    // // affiche_point_d(Or);
    // // printf("Og  : \n");
    // // affiche_point_d(Hr);
    // draw_line(pic, green, Og, Hg);
    // draw_line(pic, red, Or, Hr);
    // draw_line(pic, blue, Ob, Hb);
    // draw_line(pic, black, O, Og);
    // J'arrive bien à dessiner la figure et les sous figures ainsi je peux rentrer dans le vif du sujet

    ////////////  ETAPE 2 : GENERATION DE L'IMAGE DE LA FOUGÈRE ///////////////
    // Je n'ai finalement pas choisi d'utilisé les liste chainée dans ma version final car moins performante celon les test.
    // Cependant le code le permet en enlevant quelque comentaire "//" !

    //Vect* head = create_vect(O.x, O.y, H.x, H.y);

    P_D *tab;
    tab = malloc(2*sizeof(P_D));
    tab[0] = O;
    tab[1] = H;
 
    algo_final(pic, tab, 1, NULL);

    //draw_vector(head, pic, black);

    save_pic(pic, "pic.bmp");
    free(tab);
    //delete_list(&head);

    //Le(s) image(s) ont été créer !!

    ////////////////////////////////// ETAPE 3 : SDL //////////////////////////////////

    #ifdef SDL_VISU
    int factor = 10;
    float angle = 0;
    int speed = 10;
    SDL_Rect rect = {WIDTH/2, HEIGHT/2, WIDTH/factor, HEIGHT/factor};
    SDL_Rect collision_box = {rect.x - 180, rect.y-180, 180*2,180*2};

    SDL_Point origine_rotation = {0.0};
    // chargement de(s) image(s) :

    texture = loadImage("pic.bmp", renderer);
    
    // boucle d'affichage de SDL

    // Affichage de la fenêtre
    SDL_RenderPresent(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
    // Attente de la fermeture de la fenêtre
    SDL_Event event;
    float currentTime = SDL_GetTicks();
    float previousTime;
    float deltaTime;
    int quit = 0;
    while (!quit) {
        previousTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = currentTime - previousTime;
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                quit = 1;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_s:
                        speed ++;
                        break;
                    case SDLK_d:
                        speed --;
                        break;
                }
            }

        }
        if (deltaTime < 100){ // 100ms entre chaque frame
            SDL_Delay(100-deltaTime);
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle, &origine_rotation, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle+90, &origine_rotation, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle+180, &origine_rotation, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle+270, &origine_rotation, SDL_FLIP_NONE);

        #ifdef GAME
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &collision_box);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        #endif
        SDL_RenderPresent(renderer);
        #ifdef ROTATE
        angle += speed;
        #endif
        #ifdef MOVE
        rect.x += 10;
        if (rect.x > WIDTH -10) rect.x = 100;
        #endif
        #ifdef GAME
        collision_box.x = rect.x - 180;
        collision_box.y = rect.y - 180;
        #endif
    }


    // Nettoyage de SDL
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    #endif

    return 0;
}

