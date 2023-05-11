/*
COLLIN FLORIAN E1 ENSEIRB

"foug.h" regroupe toute les fonctions qui sont necessaire pour réaliser la fougère,
ces fonctions utilise les fonctions de "bmpTools.h" pour fonctionner.

*/

#ifndef FOUG_H
#define FOUG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmpTools.h"
#include "macro.h"
#include "listChaine.h"


/*  
trace_figure_initial :
Trace la figure initial grâce à ces points (à fournir dans l'ordre !).
*/
int trace_figure_initial(PIC pic, COLOR color, P_D p1, P_D p2, P_D p3, P_D p4, P_D p5, P_D p6);


/*
info:
Affiche les macros pour verifier.
*/
int info();


/*
init point :
fournit les coordonnées d'un point grâce à une origine, une longueur et un angle.
*/
P_D init_point(double longueur, double angle, P_D O);


/*
algo_final :
Algorithme recursif pour créer la fougère
*/
int algo_final(PIC pic, P_D *tab, int opt1, Vect** head);
int algo_final2(PIC pic, P_D *tab, int opt1);

#endif