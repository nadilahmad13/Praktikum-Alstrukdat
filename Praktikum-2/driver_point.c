#include <stdio.h>
#include "point.c"

int main(){
    POINT P1,P2;
    printf("P1\n");
    BacaPOINT(&P1);
    printf("P1 = ");
    TulisPOINT(P1);
    printf("\nP2\n");
    BacaPOINT(&P2);
    printf("P2 = ");
    TulisPOINT(P2);

    printf("\n");

    printf("\nJarak0 P1 = %f\n",Jarak0(P1));
    printf("Panjang P1 P2 = %f\n",Panjang(P1,P2));

    if(EQ(P1,P2)){
        printf("P1 = P2\n");
    
    }else{
        printf("P1 != P2\n");
    }

    if(NEQ(P1,P2)){
        printf("P1 != P2\n");
    }else{
        printf("P1 = P2\n");
    }

    if(IsOrigin(P1)){
        printf("P1 adalah titik origin\n");

    }else{
        printf("P1 bukan titik origin\n");
    }

    if(IsOnSbX(P1)){
        printf("P1 terletak pada sumbu X\n");
    }else{
        printf("P1 tidak terletak pada sumbu X\n");
    }

    if(IsOnSbY(P1)){
        printf("P1 terletak pada sumbu Y\n");

    }else{
        printf("P1 tidak terletak pada sumbu Y\n");
    }

    printf("Kuadran P1 = %d\n",Kuadran(P1));
    printf("Kuadran P2 = %d\n",Kuadran(P2));

    printf("NextX P1 = ");
    TulisPOINT(NextX(P1));

    printf("\nNextY P1 = ");
    TulisPOINT(NextY(P1));

    printf("\nPlusDelta P1 = ");
    TulisPOINT(PlusDelta(P1,1,1));

    printf("\nMirrorOf P1 = ");
    TulisPOINT(MirrorOf(P1,IsOnSbX(P1)));

    printf("\nGeser P1 = ");
    Geser(&P1,1,1);
    TulisPOINT(P1);

    printf("\nGeserKeSbX P1 = ");
    GeserKeSbX(&P1);
    TulisPOINT(P1);

    printf("\nGeserKeSbY P1 = ");
    GeserKeSbY(&P1);
    TulisPOINT(P1);

    printf("\nMirror P1 = ");
    Mirror(&P1,IsOnSbX(P1));
    TulisPOINT(P1);

    printf("\nPutar P1 = ");
    Putar(&P1,30);
    TulisPOINT(P1);

    return 0;

}