// File time.c
// Ahmad Nadil
// 13521024
// Pra Praktikum 2 Algoritma dan Struktur Data
// 7 September 2022

#include <stdio.h>
#include "time.h"

boolean IsTIMEValid(int H, int M, int S)
{
    return ((H>=0) && (H<=23) && (M>=0) && (M<=59) && (S>=0) && (S<=59));
}

void CreateTime (TIME * T, int HH, int MM, int SS)
{
    (*T).HH = HH;
    (*T).MM = MM;
    (*T).SS = SS;
}

void BacaTIME (TIME * T)
{
    int HH, MM, SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    while (!IsTIMEValid(HH,MM,SS))
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &HH, &MM, &SS);
    }
    CreateTime(T, HH, MM, SS);
}

void TulisTIME (TIME T)
{
    printf("%02d:%02d:%02d", T.HH, T.MM, T.SS);
}

long TIMEToDetik (TIME T)
{
    return (T.HH*3600 + T.MM*60 + T.SS);
}

TIME DetikToTIME (long N)
{
    TIME T;
    if (N>=86400)
    {
        N = N % 86400;
    }
    T.HH = N/3600;
    T.MM = (N%3600)/60;
    T.SS = (N%3600)%60;
    return T;
}

boolean TEQ(TIME T1, TIME T2)
{
    return ((T1.HH==T2.HH) && (T1.MM==T2.MM) && (T1.SS==T2.SS));
}

boolean TNEQ(TIME T1, TIME T2)
{
    return (!TEQ(T1,T2));
}

boolean TLT(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1)<TIMEToDetik(T2));
}

boolean TGT(TIME T1, TIME T2)
{
    return (TIMEToDetik(T1)>TIMEToDetik(T2));
}

TIME NextDetik(TIME T)
{
    return DetikToTIME(TIMEToDetik(T)+1);
}

TIME NextNDetik (TIME T, int N)
{
    return DetikToTIME(TIMEToDetik(T)+N);
}

TIME PrevDetik(TIME T)
{   
    int detik;
    detik = TIMEToDetik(T);
    if (detik-1 < 0) {
        detik = 86400;
    }
    detik -= 1;
    return DetikToTIME(detik);
}

TIME PrevNDetik (TIME T, int N)
{   
    int detik;
    detik = TIMEToDetik(T);
    if (detik-N < 0){
        detik += 86400;
    }
    detik -= N;
    return DetikToTIME(detik);
}

long Durasi (TIME TAw, TIME TAkh)
{
    int SAw, SAkh, Diff;
    SAw = TIMEToDetik(TAw);
    SAkh = TIMEToDetik(TAkh);
    Diff  = SAkh - SAw;
    if (SAw > SAkh){
        return Diff + 86400;
    }
    else{
        return Diff;
    }
}