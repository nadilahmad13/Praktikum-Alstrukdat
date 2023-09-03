#include <stdio.h>
#include "point.h"

int main() {
    POINT P[3]; // Array untuk menyimpan 3 Point
    int i;

    // Membaca 3 Point dari input
    for (i = 0; i < 3; i++) {
        BacaPOINT(&P[i]);
    }

    // Menghitung nilai a (pin rahasia) dengan menggunakan interpolasi Lagrange
    float a = 0;

    for (i = 0; i < 3; i++) {
        float Li = 1;
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                Li *= (-(float)Absis(P[j]) / (Absis(P[i]) - Absis(P[j])));
            }
        }
        a += Li * Ordinat(P[i]);
    }

    // Output Akhir
    printf("%.0f\n", a);

    return 0;
}
