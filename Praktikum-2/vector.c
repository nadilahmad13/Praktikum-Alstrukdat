// Ahmad Nadil
// 13521024
// File vector.c

#include <stdio.h>
#include <math.h>
#include "vector.h"

void CreateVector(VECTOR *v, float x, float y)
{
    AbsisComponent(*v) = x;
    OrdinatComponent(*v) = y;
}

void TulisVector(VECTOR v)
{
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}

float Magnitude (VECTOR v)
{
    return(sqrt(AbsisComponent(v)*AbsisComponent(v) + OrdinatComponent(v)*OrdinatComponent(v)));
}

VECTOR Add (VECTOR a, VECTOR b)
{
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
    CreateVector(&v, AbsisComponent(v), OrdinatComponent(v));
    return v;
}

VECTOR Substract (VECTOR a, VECTOR b)
{
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) - OrdinatComponent(b);
    CreateVector(&v, AbsisComponent(v), OrdinatComponent(v));
    return v;
}

float Dot(VECTOR a, VECTOR b)
{
    return (AbsisComponent(a) * AbsisComponent(b) + OrdinatComponent(a) * OrdinatComponent(b));
}

VECTOR Multiply(VECTOR v, float s)
{
    VECTOR a;
    AbsisComponent(a) = s * AbsisComponent(v);
    OrdinatComponent(a) = s * OrdinatComponent(v);
    CreateVector(&a, AbsisComponent(a), OrdinatComponent(a));
    return a;
}