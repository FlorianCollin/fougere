#include"bmpTools.h"
#include"mathTools.h"

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

int set_all_pix(PIC pic, COLOR color)
{
     for(int y = 0; y<pic.height; y++){
        for (int x = 0; x < pic.width; x++){
            set_pix(pic, x, y, color);

        }
    }
    return 0;
}

// Ancienne version nulle, je la laisse la pour me rappeler que je suis nulle ;)
int draw_line(PIC pic, int x1, int y1, int x2, int y2, COLOR color){
    if (x1 > pic.width) return -1;
    if (x2 > pic.width) return -1;
    if (y1 > pic.height) return -1;
    if (y2 > pic.height) return -1;
    int n;
    int tmp1,tmp2;
    tmp1 = abs(x1-x2);
    tmp2 = abs(y1-y2);
    if(tmp1>tmp2) n = tmp1;
    else n = tmp2;
    if (x1 == x2){
        if (y1<y2)
        {
            for (int k = 0; k<n+1; k++)
            {
                *(pic.pixels + x1 +((y1+k)*pic.width)) = color;
            }   
        }
        else
        {
             for (int k = 0; k<n+1; k++)
            {
                *(pic.pixels + x1 +((y1-k)*pic.width)) = color;
            }   
        }
    }
    else if(y1 == y2){
        if(x1 < x2){
            for (int k = 0; k<n+1; k++)
            {
                *(pic.pixels + x1 + k +y1*pic.width) = color;
            }   
        }
        else
        {
            for (int k = 0; k<n+1; k++)
            {
               
                *(pic.pixels + x1 - k +y1*pic.width) = color;

            }       
        }
    }
    else
    {
        if(abs(y2 - y1) == abs(x2 - x1)) //diagonale parfaite
        {
            int sx,sy;
            sx = sign(x2-x1);
            sy = sign(y2-y1);
            for (int k = 0; k<n+1; k++)
            {      
                *(pic.pixels + x1 + k*sx  +(y1+k*sy)*pic.width) = color;
            }  
        }
        else{
            double itt = 2*n;           
            double vx =((double)y2 - (double)y1)/((double)x2 -(double)x1);
            double vy =((double)x2 - (double)x1)/((double)y2 - (double)y1);
            double delta_x = (x2 - x1);
            double delta_y = (y2 - y1);
            double pas = delta_x/itt;

            double tmp_x = x1;
            double tmp_y = y1;

            for (int k = 0; k<itt; k++)
            {

                tmp_x += pas;
                tmp_y += pas*vx;
                *(pic.pixels +  (int)tmp_x  + (int)tmp_y*pic.width) = color;

            }     


        }
    }
    return 0;
}

// version qui à la classe et qui utilise l'alorithme de Bresenham
int draw_line2(PIC pic, int x1, int y1, int x2, int y2, COLOR color){
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;
    int e2;
 
    while (1) {
        set_pix(pic, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
 
    return 0;
}
