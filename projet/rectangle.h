#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "point.h"

typedef struct rectangle{

    SDL_Rect taille;
    int R;
    int G;
    int B;
    int A;

}rectangle;

extern void initRec (rectangle *rec, int xDepart, int yDepart,int xFin, int yFin, int R, int G, int B, int A);

extern void getRecX (rectangle rec);
extern void getRecY (rectangle rec);

extern void setRecX (rectangle *rec, int xDepart, int xFin);
extern void setRecY (rectangle *rec, int yDepart, int yFin);


#endif
