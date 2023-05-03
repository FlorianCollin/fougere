#ifndef BMP_H
#define BMP_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mathTools.h"
#include "macro.h"

typedef struct color COLOR;
typedef struct picture PIC;
// definition des structures

struct color{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};


struct picture{
    int width;
    int height;
    COLOR *pixels;
};

PIC new_pic(int width, int height);
int save_pic(PIC pic, const char* file_name);
int set_pix(PIC pic, int x, int y, COLOR color);
int set_all_pix(PIC pic, COLOR color);
int draw_line(PIC pic, COLOR color, P_D p1, P_D p2);
#endif