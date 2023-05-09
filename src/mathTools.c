#include "mathTools.h"

int min(int a, int b){
    if(a>=b) return a;
    if(a<b) return b;
    return 0;

}

int max(int a, int b){
    if(a>=b) return b;
    if(a<b) return a;
    return 0;

}

int sign(int a){
    if(a>=0) return 1;
    else return -1;
    return 0;
}

void affiche_point_d(P_D m) {
    printf("(%f, %f)\n", m.x, m.y);
}

// void affiche_point_i(P_I m) {
//     printf("(%d, %d)\n", m.x, m.y);
// }

P_D calcul_vector(P_D O, P_D H) {
    P_D OH_vector;
    OH_vector.x = H.x - O.x;
    OH_vector.y = H.y - O.y;
    return OH_vector;
}
double calcul_norme(P_D vector) {
    double norme = 0;
    norme = sqrt((vector.x * vector.x) + (vector.y * vector.y));
    return norme;
}
