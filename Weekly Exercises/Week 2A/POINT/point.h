#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct Point{
    float x;
    float y;
} point;

#define ABSIS(p) (p).x
#define ORDINAT(p) (p).y

void createPoint (point* p, float x, float y);
boolean isOrigin (point p);
void readPoint (point * p);
void displayPoint (point p);
point move(point p, float dx, float dy);

#endif