// Nama : Ahmad Nadil
// NIM  : 13521024
// K03 Algoritma dan Struktur Data

#include <stdio.h>

int IsWithinRange(int ip){
    if (ip >= 0 && ip <= 4){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    float ip, rata = 0;
    int n = 0, lulus = 0, tlulus = 0;
    while (ip != -999)
    {   
        scanf("%f",&ip);
        if (IsWithinRange(ip) == 1 && ip >= 0 && ip <= 4){
            n++;
            rata +=ip;
            if(ip >= 2.75 && ip <= 4.0){
                lulus++;
            }
            else{
                tlulus++;
            }
        }
    }
    if(n > 0){
        printf("%d\n",n);
        printf("%d\n",lulus);
        printf("%d\n",tlulus);
        printf("%.2f\n",rata/n);
    }
    else{
        printf("Tidak ada data\n");
    }

    return 0;
}
