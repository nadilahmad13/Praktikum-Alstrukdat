#include <stdio.h>
#include <math.h>
#include "garis.h"

float JarakTitikKeGaris(GARIS L, POINT P)
// Menghitung jarak titik P ke garis L
{
    float m = Gradien(L);
    float c = L.PAw.Y - m * L.PAw.X;
    float jarak = (m * P.X - P.Y + c) / sqrt(m * m + 1);
    return jarak;
}

int main(){
    // Inisialisasi Variabel
    int i, b, n, ctr = 0;
    GARIS L;

    // Input b
    scanf("%d",&b);

    // Input Garis
    BacaGARIS(&L);

    // Input n
    scanf("%d",&n);

    // Menghitung banyaknya biri-biri yang perlu diselamatkan
    for (i = 0 ; i < n ; i++){
        // Input titik
        POINT p;
        BacaPOINT(&p);

        // Hitung jarak biri2 ke garis serigala
        float d = JarakTitikKeGaris(L, p);
        printf("%.2f\n",d);

        // Jika terpenuhi, maka biri-biri harus diselamatkan
        if (d <= b) ctr++;
    }

    // Output akhir
    printf("%d\n",ctr);
    
    return 0;
}