// Nama : Ahmad Nadil
// NIM  : 13521024
// K03 Algoritma dan Struktur Data

#include <stdio.h>

int main()
{
    // IP Input
    float ip,gaji;
    scanf("%f %f",&ip,&gaji);

    // Percabangan
    if (ip >= 3.5){
        printf("%d\n",4);
    }
    else if(ip < 3.5 && gaji < 1){
        printf("%d\n",1);
    }
    else if(gaji >= 1 && gaji < 5 && ip < 3.5){
        if (ip >= 2.0){
            printf("%d\n",3);
        }
        else{
            printf("%d\n",2);
        }
    }
    else{
        printf("%d\n",0);
    }

    return 0;
}