// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 14 September 2022
// Topik praktikum  : ADT List Statik dan Dinamik
// Deskripsi        : File "olist.c"

#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"

int main()
{
    //Read List
    ListStatik l;
    readList(&l);

    //2. X Occurence
    int x,xocc = 0;
    scanf("%d",&x);
    int i;
    for (i = 0 ; i < listLength(l) ; i++){
        if (x == ELMT(l,i)){
            xocc++;
        }
    }

    // 1. Print List
    printList(l);
    printf("\n");

    printf("%d\n",xocc);

    //3. Get Last Index where X is Found
    int ldx;
    if (indexOf(l,x) != IDX_UNDEF){
        for (i = 0 ; i < listLength(l) ; i++){
            if (x == ELMT(l,i)){
                ldx = i;
            }
        }
        printf("%d\n",ldx);
    }
    else{
        printf("%d tidak ada\n",x);
    }

    //4. X Extreme Values
    int min,max;
    extremeValues(l,&max,&min);

    if (x == max){
        printf("maksimum\n");
    }

    if (x == min){
        printf("minimum\n");
    }

    // 5. Get the median of List
    sortList(&l,true);
    int med = ELMT(l,getLastIdx(l)/2);
    if (x == med){
        printf("median\n");
    }

    return 0;
}