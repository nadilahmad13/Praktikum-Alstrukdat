#include <stdio.h>
#include "time.h"

int main(){
    // Inisialisasi Variabel
    int n, i;
    TIME min, max;
    scanf("%d",&n);
    
    CreateTime(&min,23,59,59);
    CreateTime(&max,0,0,0);

    // Loop sebanyak n kali
    for (i = 1; i <= n; i++){
        printf("[%d]\n",i);

        // Baca Time
        TIME T1, T2;
        BacaTIME(&T1);
        BacaTIME(&T2);

        // Menentukan awal dan akhir
        TIME awal, akhir;
        if (TLT(T1,T2)) {
            awal = T1;
            akhir = T2;
        } else {
            awal = T2; 
            akhir = T1;
        }

        // Perhitungan durasi
        long durasi = Durasi(awal,akhir);
        printf("%ld\n",durasi);

        if (TLT(awal,min)) min = awal;
        if (TLT(max,akhir)) max = akhir;
    }

    // Output akhir
    TulisTIME(min);
    printf("\n");
    TulisTIME(max);
    printf("\n");

    return 0;
}