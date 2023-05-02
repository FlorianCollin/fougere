#include "mathTools.h"

int min(int a, int b){
    if(a>=b) return a;
    if(a<b) return b;
}

int max(int a, int b){
    if(a>=b) return b;
    if(a<b) return a;
}

int sign(int a){
    if(a>=0) return 1;
    else return -1;
}
