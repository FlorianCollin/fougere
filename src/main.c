/*
COLLIN FLORIAN E1 ENSEIRB

POJET C

Ce programme ce trouve dans le cadre d'un projet scolaire en 1er année d'Électronique à l'ENSEIRB MATMECA.
L'objectif finale de ce projet et de réaliser une fractale / image de fougère au format .bmp


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Les fonctions et les macros sont inclus grace au fichier ci dessous.
#include "bmpTools.h"
#include "mathTools.h"
#include "macro.h"
#include "foug.h"


int main() {

    // COLOR 
    const COLOR black = {0, 0, 0};
    const COLOR gris = {255,200, 200};
    const COLOR marque = {255, 0, 255};
    const COLOR cyan = {0,255,255};
    const COLOR white = {255,255,255};

    P_D O;
    O.x = 10.0;
    O.y = 424;

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

    // test de draw_line
    // P_D P1 = {0,0};
    // P_D P2 = {50,20};
    // draw_line(pic, black, A, B);

    ////////////  ETAPE 1 : TEST  ////////////
    
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

    P_D *tab;
    tab = malloc(2*sizeof(P_D));
    tab[0] = O;
    tab[1] = H;
 
    algo_final(pic, tab);

    //sauvegarde du pic
    save_pic(pic, "pic.bmp");
    free(tab);

    return 0;
}

