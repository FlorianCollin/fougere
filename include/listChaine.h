// Je n'ai finalement pas choisi d'utilisé les liste chainée dans ma version final car moins performante celon les test, cependant le code le permet !

#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmpTools.h"

typedef struct vect Vect;

struct vect{
    double x1;
    double y1;
    double x2;
    double y2;
    struct vect *next;
};

Vect *create_vect(double x1, double y1, double x2, double y2);
void add_vect(Vect **head, double x1, double y1, double x2, double y2);
void print_vect(Vect *v);
void print_list(Vect *head);
void delete_list(Vect **head);
void draw_vector(Vect *head, PIC pic, COLOR color);

#endif