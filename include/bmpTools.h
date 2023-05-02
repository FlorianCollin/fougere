#ifndef BMP_H
#define BMP_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
int draw_line(PIC pic, int x1, int y1, int x2, int y2, COLOR color);
int draw_line2(PIC pic, int x1, int y1, int x2, int y2, COLOR color);
#endif