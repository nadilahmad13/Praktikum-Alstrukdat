#include <stdio.h>
#include "point.h"

void createPoint(point *p, float x, float y)
{
    ABSIS(*p) = x;
    ORDINAT(*p) = y;
}

boolean isOrigin (point p)
{
    return (ABSIS(p) == 0) && (ORDINAT(p) == 0);
}

void readPoint (point *p)
{
    float x,y;
    scanf("%f %f", &x, &y);
    createPoint(p, x, y);
}

void displayPoint (point p)
{
    printf("(%.2f, %.2f)", ABSIS(p), ORDINAT(p));
}

point move (point p, float dx, float dy)
{
    point pt;
    createPoint(&pt, ABSIS(p) + dx, ORDINAT(p) + dy);
    return pt;
}