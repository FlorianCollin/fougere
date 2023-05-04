#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmpTools.h"
#include "mathTools.h"
#include "macro.h"
#include "foug.h"

int algo_final(PIC pic, P_D *tab);
/*
Consigne memo :

le premier segment de la tige de base part
horizontalement, vers la droite, depuis les coordonnées x = 10, y = 424 (le point de référence est le
pixel en haut à gauche). Le facteur d’échelle sera fixé à 1500.

*/

COLOR red = {255, 0, 0};
COLOR blue = {0, 255, 0};
COLOR green = {0, 0, 255};
COLOR black = {0, 0, 0};


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
    COLOR gris = {255,200, 200};

    COLOR magenta = {255, 0, 255};
    COLOR cyan = {0,255,255};
    COLOR white = {255,255,255};
    


    PIC pic  = new_pic(WIDTH, HEIGHT);
    set_all_pix(pic, white);

    // manipulation du pic
    draw_line(pic, gris, O, H);
    trace_figure_initial(pic, gris, O, A, B, C, D, E); // on trace la première figure

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

    // maintenant commencons à definir la logique de notre algorithme

    /*
    Pour ce qui est du dessin sur le pic on aurra tjr juste à dessiner [OOg]
    Il va falloir bien choisir comment gérer nos variables temporelles et le choix des fonctions
    
    formule pour pouvoir faire le nouveau point Og Or Ob

    // il y a plusieur méthode géometrique 

    */
    
    P_D *tab;
    tab = malloc(2*sizeof(P_D));
    tab[0] = O;
    tab[1] = H;
    algo_final(pic, tab);



    //sauvegarde du pic
    save_pic(pic, "premier_pic.bmp");
    free(tab);

    return 0;
}

int algo_final(PIC pic, P_D *tab) {
    
    static int compt = 0; // la variable n'est affectée que la première fois
        
    // calcul des valeurs necessaires pour la suite :
    P_D OH_vector = calcul_vector(tab[0], tab[1]);
    double norme_OH = calcul_norme(OH_vector);
    double angle = 0;
    printf("OH :  ");
    affiche_point_d(OH_vector);
    angle = - atan(OH_vector.y / OH_vector.x) ;

    // Figure Verte :

    // calcul de Og et Hg sachant O et H
    P_D Og, Hg;

    Og.x = tab[0].x + OOg * OH_vector.x;
    Og.y = tab[0].y + OOg * OH_vector.y;
    affiche_point_d(Og);
    Hg = init_point(OgHg*OH, HOgHg + angle, Og);
    affiche_point_d(Hg);
    if (draw_line(pic, green, Og, Hg)) {
        return -1;
    }
    if (draw_line(pic, black,  tab[0], Og)) {
        return -2;
    }
    if (set_pixV2(pic, red, tab[0])) {
        return -3;
    }
    if (set_pixV2(pic, red, Og)) {
        return -4;
    }

    // Figure Rouge

    



    tab[0] = Og;
    tab[1] = Hg;
    compt ++;
    if (compt >= 5) return 0;
    else algo_final(pic, tab);
    //note le critère d'arret de notre recursivité sera la taille de OH    
}

