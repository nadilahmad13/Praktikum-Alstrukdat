#include <stdio.h>
#include "time.c"

int main(){
    TIME T1, T2;
    printf("BACA TIME\n");
    BacaTIME(&T1);
    BacaTIME(&T2);

    // TULIS TIME
    printf("TULIS TIME\n");
    printf("T1 = ");
    TulisTIME(T1);
    printf("\nT2 = ");
    TulisTIME(T2);
    printf("\n");

    // TIME TO DETIK
    printf("TIME TO DETIK\n");
    printf("T1 = %ld detik\n",TIMEToDetik(T1));
    printf("T2 = %ld detik\n",TIMEToDetik(T2));

    // DETIK TO TIME
    printf("DETIK TO TIME\n");
    printf("T1 = ");
    TulisTIME(DetikToTIME(TIMEToDetik(T1)));
    printf("\nT2 = ");
    TulisTIME(DetikToTIME(TIMEToDetik(T2)));
    printf("\n");

    // TEQ
    printf("TEQ\n");
    if(TEQ(T1,T2)){
        printf("T1 = T2\n");
    }else{
        printf("T1 != T2\n");
    }

    // TNEQ
    printf("TNEQ\n");
    if(TNEQ(T1,T2)){
        printf("T1 != T2\n");
    }else{
        printf("T1 = T2\n");
    }

    // TLT
    printf("TLT\n");
    if(TLT(T1,T2)){
        printf("T1 < T2\n");
    }else{
        printf("T1 > T2\n");
    }

    // TGT
    printf("TGT\n");
    if(TGT(T1,T2)){
        printf("T1 > T2\n");
    }else{
        printf("T1 < T2\n");
    }


    // NextDetik
    printf("NextDetik\n");
    printf("T1 = ");
    TulisTIME(NextDetik(T1));
    printf("\nT2 = ");
    TulisTIME(NextDetik(T2));
    printf("\n");

    // NextNDetik
    printf("NextNDetik\n");
    printf("T1 = ");
    TulisTIME(NextNDetik(T1,10));
    printf("\nT2 = ");
    TulisTIME(NextNDetik(T2,10));
    printf("\n");

    // PrevDetik
    printf("PrevDetik\n");
    printf("T1 = ");
    TulisTIME(PrevDetik(T1));
    printf("\nT2 = ");
    TulisTIME(PrevDetik(T2));
    printf("\n");

    // PrevNDetik
    printf("PrevNDetik\n");
    printf("T1 = ");
    TulisTIME(PrevNDetik(T1,10));
    printf("\nT2 = ");
    TulisTIME(PrevNDetik(T2,10));
    printf("\n");

    // Durasi
    printf("Durasi\n");
    printf("T1-T2 = %ld detik\n",Durasi(T1,T2));
    printf("T2-T1 = %ld detik\n",Durasi(T2,T1));

    return 0;

}