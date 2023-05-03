#ifndef FOUG_H
#define FOUG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmpTools.h"

int trace_figure_initial(PIC pic, COLOR color, P_D p1, P_D p2, P_D p3, P_D p4, P_D p5, P_D p6);
int info();
P_D init_point(double longueur, double angle, P_D O);


#endif