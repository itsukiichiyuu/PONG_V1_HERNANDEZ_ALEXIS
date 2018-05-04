#include "point.h"

void initPos (point *mPoint, double x, double y)
{
    mPoint->x=x;
    mPoint->y=y;
}

double getPosX (point mPoint)
{
    return mPoint.x;
}

double getPosY (point mPoint)
{
    return mPoint.y;
}

void setPosX (point *mPoint, double x)
{
    mPoint->x=x;
}

void setPosY (point *mPoint, double y)
{
    mPoint->y=y;
}
