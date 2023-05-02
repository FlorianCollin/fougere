#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bmpTools.h"

// define : ( je definie bcp de define pour me simplifier la vie hihi ;) )

// Longueur :

#define OH 1.0 //taille de reference
#define OA 0.98/OH
#define OB 0.877/OH
#define OC 1.086/OH
#define OD 0.765/OH
#define OE 0.339/OH

// Angle :

#define HOA 0.9421
#define HOB -0.0647
#define HOC -0.3
#define HOD -0.263
#define HOE -1.175

#define W 1600 //width
#define H 900 //height


int main() {
    COLOR black = {0, 0, 0};
    COLOR red = {255, 0, 0};
    COLOR blue = {0, 255, 0};
    COLOR green = {0, 0, 255};
    COLOR magenta = {255, 0, 255};
    COLOR cyan = {0,255,255};
    COLOR white = {255,255,255};
    
    printf("hello world");

    PIC pic_test  = new_pic(W, H);
    set_all_pix(pic_test, red);
    draw_line2(pic_test,2,2,62,80,cyan);
    save_pic(pic_test, "premier_pic.bmp");


    return 0;
}


