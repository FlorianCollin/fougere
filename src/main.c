#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmpTools.h"
#include "mathTools.h"
#include "macro.h"
#include "foug.h"


/*
Consigne memo :

le premier segment de la tige de base part
horizontalement, vers la droite, depuis les coordonnées x = 10, y = 424 (le point de référence est le
pixel en haut à gauche). Le facteur d’échelle sera fixé à 1500.

*/



int main() {
    // premier test et initilsation des variables utiles.
    // On definit le premier point avec les conditions initial.
    P_D O;
    O.x = 10.0;
    O.y = 424;
    // Petit test pour voir si tout est OK!
    printf("hello world\n");
    info();
    // On definit les coordonnées exacts de tout les premiers points
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
    

    // COLOR 
    COLOR black = {0, 0, 0};
    COLOR red = {255, 0, 0};
    COLOR blue = {0, 255, 0};
    COLOR green = {0, 0, 255};
    COLOR magenta = {255, 0, 255};
    COLOR cyan = {0,255,255};
    COLOR white = {255,255,255};
    


    PIC pic  = new_pic(WIDTH, HEIGHT);
    set_all_pix(pic, white);

    // manipulation du pic
    draw_line(pic, blue, O, H);
    trace_figure_initial(pic, blue, O, A, B, C, D, E);
    set_pixV2(pic, red, O);
    set_pixV2(pic, red, H);
    set_pixV2(pic, red, A);
    set_pixV2(pic, red, B);
    set_pixV2(pic, red, C);
    set_pixV2(pic, red, D);
    set_pixV2(pic, red, E);



    //sauvegarde du pic
    save_pic(pic, "premier_pic.bmp");


    return 0;
}



