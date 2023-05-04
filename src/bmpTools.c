#include"bmpTools.h"


PIC new_pic(int width, int height){
    PIC np;
    np.width = width;
    np.height = height;
    np.pixels = malloc(sizeof(COLOR)*width*height);
    return np;
}


int save_pic(PIC pic, const char* file_name){


    int max_color = 255; 

    FILE *fp;

    fp = fopen(file_name, "w");

    if (fp == NULL) return 1;

    fprintf(fp, "P6 ");
    fprintf(fp, "%d %d ", pic.width, pic.height);
    fprintf(fp, "%d ", max_color);

    COLOR tmp_pal;
    for (int y = 0; y < pic.height; y++)
        {
            for (int x = 0; x < pic.width; x++)
            {   
                    tmp_pal = *(pic.pixels + x + y*pic.width);
                    fwrite(&tmp_pal.red, 1, 1, fp);
                    fwrite(&tmp_pal.blue, 1, 1, fp);
                    fwrite(&tmp_pal.green, 1, 1, fp);
            }
        }
    fclose(fp);
    return 0;
}

int set_pix(PIC pic, int x, int y, COLOR color){

    *(pic.pixels+ x + y*pic.width) = color;

    return 0;
}

int set_pixV2(PIC pic, COLOR color, P_D p) {
    if ((int)(p.x) >  pic.width || (int)(p.x) < 0 || (int)(p.y) > pic.height || (int)(p.y) < 0) {
        printf("ERROR SP1");
        return -1;
    }
    else *(pic.pixels+ (int)(p.x) + (int)(p.y)*pic.width) = color;

    return 0;
}

int set_all_pix(PIC pic, COLOR color)
{
     for(int y = 0; y<pic.height; y++){
        for (int x = 0; x < pic.width; x++){
            set_pix(pic, x, y, color);

        }
    }
    return 0;
}


int draw_line(PIC pic, COLOR color, P_D p1, P_D p2) {
    int dx = abs((int)(p2.x) - (int)(p1.x));
    int dy = abs((int)(p2.y) - (int)(p1.y));
    int sx = (int)(p1.x) < (int)(p2.x) ? 1 : -1;
    int sy = (int)(p1.y) < (int)(p2.y) ? 1 : -1;
    int err = dx - dy;
    int e2;
 
    while (1) {
        if ((int)(p1.x) >  pic.width || (int)(p1.x) < 0 || (int)(p1.y) > pic.height ||(int)(p1.y) < 0) {
            printf("ERROR DL1\n");
            return 1;
        }
        else set_pixV2(pic, color, p1);
        if ((int)(p1.x) == (int)(p2.x) && (int)(p1.y) == (int)(p2.y)) break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; (p1.x) += sx; }
        if (e2 < dx) { err += dx; (p1.y) += sy; }
    }
 
    return 0; 
}