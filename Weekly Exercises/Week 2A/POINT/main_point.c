#include <stdio.h>
#include "point.c"

int main()
{
    point p, p1;
    float dx,dy;

    printf("Masukkan absis dan ordinat: ");
    readPoint(&p);

    printf("Titik yang dibaca ");
    displayPoint(p);
    if (isOrigin(p))
    {
        printf(" adalah titik origin");
    }

    printf("\n");

    printf("Geser di arah sumbu x sebesar = ");
    scanf("%f", &dx);
    printf("Geser di arah sumbu y sebesar = ");
    scanf("%f", &dy);
    printf("Setelah digeser = ");
    displayPoint(move(p, dx, dy));
    printf("\n");

    return 0;
}