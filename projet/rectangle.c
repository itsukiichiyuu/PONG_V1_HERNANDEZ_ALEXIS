#include "rectangle.h"

//fonction rectangle: prend le X, le Y, la couleur et l'objet


extern void initRec (rectangle *rec, int xDepart, int yDepart,int xFin, int yFin, int R, int G, int B, int A)
{
    rec->taille.x=xDepart;
    rec->taille.y=yDepart;
    rec->taille.w=xFin;
    rec->taille.h=yFin;
    rec->R=R;
    rec->G=G;
    rec->B=B;
    rec->A=A;
};

extern void getRecX (rectangle rec);
extern void getRecY (rectangle rec);

extern void setRecX (rectangle *rec, int xDepart, int xFin)
{
    rec->taille.x=xDepart;
    rec->taille.w=xFin;
}

extern void setRecY (rectangle *rec, int yDepart, int yFin)
{
    rec->taille.y=yDepart;
    rec->taille.h=yFin;
}
