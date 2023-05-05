/*
Fonctionnement de ma liste chainée :
Reprise du dernier TP ainsi on a pas l'utilisation de P_D.

*/


#include "listChaine.h"


Vect *create_vect(double x1, double y1, double x2, double y2) {
    Vect *v = (Vect *)malloc(sizeof(Vect));
    if (v == NULL) {
        printf("Erreur : Impossible d'allouer de la mémoire\n");
        exit(1);
    }
    v->x1 = x1;
    v->y1 = y1;
    v->x2 = x2;
    v->y2 = y2;
    v->next = NULL;
    return v;
}

void add_vect(Vect **head, double x1, double y1, double x2, double y2) {
    Vect *v = create_vect(x1, y1, x2, y2);
    if (*head == NULL) {
        *head = v;
    } else {
        Vect *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = v;
    }
}

void print_vect(Vect *v) {
    printf("(%f, %f) -> (%f, %f)\n", v->x1, v->y1, v->x2, v->y2);
}

void print_list(Vect *head) {
    Vect *current = head;
    while (current != NULL) {
        print_vect(current);
        current = current->next;
    }
}

void delete_list(Vect **head) {
    Vect *current = *head;
    while (current != NULL) {
        Vect *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}


void draw_vector(Vect *head, PIC pic, COLOR color)
{
    printf("draw_vector\n");
    P_D P1, P2;
    Vect *current = head;
    double x1,y1,x2,y2;
    while (current != NULL) {
        P1.x = current->x1;
        P1.y = current->y1;
        P2.x = current->x2;
        P2.y = current->y2;

        draw_line(pic, color, P1, P2);
        current = current->next;
    }


}