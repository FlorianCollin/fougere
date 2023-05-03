#include "foug.h"

int trace_figure_initial(PIC pic, COLOR color, P_D p1, P_D p2, P_D p3, P_D p4, P_D p5, P_D p6) {
    draw_line(pic, color, p1, p2);
    draw_line(pic, color, p2, p3);
    draw_line(pic, color, p3, p4);
    draw_line(pic, color, p4, p5);
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