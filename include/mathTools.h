/*
COLLIN FLORIAN E1 ENSEIRB

Vous trouverez ici toute les fonctions d'ordre mathématique et d'affichage d'information.
Ainsi que les definitions de la structure P_D essentiel au projet.


*/


#ifndef MATH_H
#define MATH_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point_double P_D;
//typedef struct point_int P_I;

struct point_double{
    double x;
    double y;
};

// struct point_int{
//     int x;
//     int y;
// };

// Fonction mathématique élémentaire
int max(int a, int b);
int min(int a, int b);
int sign(int a);



P_D calcul_vector(P_D O, P_D H);

double calcul_norme(P_D vector);

void affiche_point_d(P_D m);

// void affiche_point_i(P_I m);

#endif