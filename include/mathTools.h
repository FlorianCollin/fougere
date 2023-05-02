#ifndef MATH_H
#define MATH_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point_double P_D;
typedef struct point_int P_I;

struct point_double{
    double x;
    double y;
};

struct point_int{
    int x;
    int y;
};

int max(int a, int b);
int min(int a, int b);
int sign(int a);

#endif