// File point.c
// Ahmad Nadil
// 13521024
// Pra Praktikum 2 Algoritma dan Struktur Data
// 7 September 2022
#include <stdio.h>
#include "point.h"
#include <math.h>

// #ifndef M_PI
// #define M_PI 3.14159265358979323846264338327950288
// #endif

void CreatePoint (POINT * P, float X, float Y)
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P)
{
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P)
{
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}

boolean EQ (POINT P1, POINT P2)
{
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2)
{
    return !EQ(P1, P2);
}

boolean IsOrigin (POINT P)
{
    return (Absis(P) == (float)0) && (Ordinat(P) == (float)0);
}

boolean IsOnSbX(POINT P)
{
    return Ordinat(P) == 0;
}

boolean IsOnSbY(POINT P)
{
    return Absis(P) == 0;
}

int Kuadran (POINT P)
{
    if (Absis(P) > 0 && Ordinat(P) > 0)
        return 1;
    else if (Absis(P) < 0 && Ordinat(P) > 0)
        return 2;
    else if (Absis(P) < 0 && Ordinat(P) < 0)
        return 3;
    else if (Absis(P) > 0 && Ordinat(P) < 0)
        return 4;
}

POINT NextX (POINT P)
{
    Absis(P)++;
    return P;
}

POINT NextY (POINT P)
{
    Ordinat(P)++;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
{   
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX)
{
    POINT P1;
    if (SbX){
        Ordinat(P) = -1 * Ordinat(P);
    }
    else{
        Absis(P) = -1 * Absis(P);
    }
    return P;
}

float Jarak0(POINT P)
{
    return sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P));
}

float Panjang(POINT P1, POINT P2)
{
    return sqrt((Absis(P1) - Absis(P2)) * (Absis(P1) - Absis(P2)) + (Ordinat(P1) - Ordinat(P2)) * (Ordinat(P1) - Ordinat(P2)));
}

void Geser (POINT *P, float deltaX, float deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P)
{
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P)
{
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX)
{
    if (SbX && Ordinat(*P) != 0){
        Ordinat(*P) = -1 * Ordinat(*P);
    }
    else if (!SbX && Absis(*P) != 0){
        Absis(*P) = -1 * Absis(*P);
    }
}

void Putar (POINT *P, float Sudut)
{
    float X, Y;
    X = Absis(*P);
    Y = Ordinat(*P);
    Sudut = Sudut * 3.141592 / 180;
    Absis(*P) = X * cos(Sudut) + Y * sin(Sudut);
    Ordinat(*P) = -1 * X * sin(Sudut) + Y * cos(Sudut);
}       