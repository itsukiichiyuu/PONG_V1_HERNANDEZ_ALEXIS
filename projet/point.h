#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "constantes.h"

typedef struct point{

    double x;
    double y;

}point;

extern void initPos (point *mPoint, double x, double y);

extern double getPosX (point mPoint);
extern double getPosY (point mPoint);

extern void setPosX (point *mPoint, double x);
extern void setPosY (point *mPoint, double y);

#endif
