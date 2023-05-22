// Ahmad Nadil
// 13521024
// File garis.c

#include <stdio.h>
#include <math.h>
#include "garis.h"

void CreateGaris (GARIS * L, POINT P1, POINT P2)
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS(GARIS * L)
{
    BacaPOINT(&PAwal(*L));
    BacaPOINT(&PAkhir(*L));
    while(EQ(PAwal(*L),PAkhir(*L)))
    {
        printf("Garis tidak valid\n");
        BacaPOINT(&PAwal(*L));
        BacaPOINT(&PAkhir(*L));
    }
    CreateGaris(L,PAwal(*L),PAkhir(*L));
}

void TulisGARIS(GARIS L)
{
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}

float PanjangGARIS (GARIS L)
{
    float x1, y1, x2, y2;
    x1 = Absis(PAwal(L));
    y1 = Ordinat(PAwal(L));
    x2 = Absis(PAkhir(L));
    y2 = Ordinat(PAkhir(L));
    return(sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
}

float Gradien (GARIS L)
{   
    return ((Ordinat(PAkhir(L))-Ordinat(PAwal(L)))/(Absis(PAkhir(L))-Absis(PAwal(L))));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
    Geser(&PAwal(*L), deltaX, deltaY);
    Geser(&PAkhir(*L), deltaX, deltaY);
}

boolean IsTegakLurus (GARIS L1, GARIS L2)
{
    return (Gradien(L1) * Gradien (L2) == -1);
}

boolean IsSejajar(GARIS L1, GARIS L2)
{
    return (Gradien(L1) == Gradien(L2));
}