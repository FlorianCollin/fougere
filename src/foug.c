#include "foug.h"

int trace_figure_initial(PIC pic, COLOR color, P_D p1, P_D p2, P_D p3, P_D p4, P_D p5, P_D p6) {
    draw_line(pic, color, p1, p2);
    draw_line(pic, color, p2, p3);
    draw_line(pic, color, p3, p4);
    draw_line(pic, color, p4, p5);
    draw_line(pic, color, p5, p6);
    draw_line(pic, color, p6, p1);
   return 0;
}



int info(){
    printf("Longueurs :\n");
    printf("OH = %f\n", OH);
    printf("OA = %f\n", OA);
    printf("OB = %f\n", OB);
    printf("OC = %f\n", OC);
    printf("OD = %f\n", OD);
    printf("OE = %f\n", OE);

    printf("Angles :\n");
    printf("HOA = %f\n", HOA);
    printf("HOB = %f\n", HOB);
    printf("HOC = %f\n", HOC);
    printf("HOD = %f\n", HOD);
    printf("HOE = %f\n", HOE);
    return 0;
}



P_D init_point(double longueur, double angle, P_D O) {
    // ici on Créer le point M, cela ce fait en connaissance de la distance OM fournit par "longeur" et d'ange avec "angle" en radian.
    P_D m;
    m.x = O.x + ( longueur * cos(angle) );
    m.y = O.y - ( longueur * sin(angle) ); // le signe "-" est du au sens du repère
    return  m;
}



int algo_final(PIC pic, P_D *tab) {
    
    COLOR red = {255, 0, 0};
    COLOR blue = {0, 255, 0};
    COLOR green = {0, 0, 255};
    COLOR black = {0, 0, 0};


    static int compt_g = 0; // la variable n'est affectée que la première fois
    static int compt_b = 0;
    static int compt_r = 0;
    int compt = compt_b + compt_g + compt_r;

    printf("\n\nO : ");
    affiche_point_d(tab[0]);
    printf("H : ");
    affiche_point_d(tab[1]);

    // calcul des valeurs necessaires pour la suite :
    P_D OH_vector = calcul_vector(tab[0], tab[1]);
    double norme_OH = calcul_norme(OH_vector);

    printf("norme OH : %f\n", norme_OH);

    double angle = 0;
    printf("OH :  ");
    affiche_point_d(OH_vector);
    angle = atan2(OH_vector.y, OH_vector.x);

    printf("angle : %f rad / %f deg\n", angle, angle*180.0/3.141592);

    // Figure Verte :

    // calcul de Og et Hg sachant O et H
    P_D Og, Hg;

    Og.x = tab[0].x + OOg * OH_vector.x;
    Og.y = tab[0].y + OOg * OH_vector.y;
    printf("Og : ");
    affiche_point_d(Og);
    Hg = init_point(OgHg*norme_OH, HOgHg - angle, Og);
    printf("Hg : ");
    affiche_point_d(Hg);
    // if (draw_line(pic, green, Og, Hg)) {
    //     return -1;
    // }
    if (draw_line(pic, black,  tab[0], Og)) {
        return -2;
    }
    // if (set_pixV2(pic, marque, tab[1])) {
    //     return -3;
    // }
    // if (set_pixV2(pic, marque, Og)) {
    //     return -4;
    // }

    // Figure Rouge

    P_D Or, Hr;

    Or.x = tab[0].x + OOr * OH_vector.x;
    Or.y = tab[0].y + OOr * OH_vector.y;
    printf("Or : ");
    affiche_point_d(Or);
    Hr = init_point(OrHr*norme_OH, HOrHr - angle, Or);
    printf("Hr : ");
    affiche_point_d(Hr);


    // Figure Bleu

    P_D Ob, Hb;
    //draw_line(pic, red, tab[0], tab[1]);
    Ob.x = tab[0].x + OOb * OH_vector.x;
    Ob.y = tab[0].y + OOb * OH_vector.y;
    printf("norme OOb : %f\n", calcul_norme(calcul_vector(tab[0], Ob)));
    printf("Ob : ");
    affiche_point_d(Ob);
    Hb = init_point(ObHb*norme_OH, HObHb - angle , Ob);
    printf("Hb : ");
    affiche_point_d(Hb);
    // draw_line(pic, marque, tab[0], Ob);
    // draw_line(pic, blue, Ob, Hb);


    // tab[0] = Ob;
    // tab[1] = Hb;

    tab[0] = Ob;
    tab[1] = Hb;
    compt_b ++;
    if (norme_OH < 20){
        printf("compt blue : %d\n", compt_b);
        return 0;

    }
    else algo_final(pic, tab);

    tab[0] = Og;
    tab[1] = Hg;
    compt_g ++;
    if (norme_OH < 20) {
        printf("compt green : %d\n", compt_g);
        return 0;
    }
    else algo_final(pic, tab);

    tab[0] = Or;
    tab[1] = Hr;
    compt_r ++;
    if (norme_OH < 20){
        printf("compt red : %d\n", compt_r);
        return 0;
    }
    else algo_final(pic, tab);
    
    
    //note le critère d'arret de notre recursivité sera la taille de OH    
}
