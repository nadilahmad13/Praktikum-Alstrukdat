// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 14 September 2022
// Topik praktikum  : ADT List Statik dan Dinamik
// Deskripsi        : File "intersect.c"

#include <stdio.h>
#include <stdlib.h>
#include "liststatik.h"

int main(){
    ListStatik l1,l2,l3;
    CreateListStatik(&l3);
    readList(&l1);
    readList(&l2);

    if (isEmpty(l1) || isEmpty(l2)){
        printf("%d\n[]\n",0);
    }

    else{
        sortList(&l1,true);
        sortList(&l2,true);
        int i,j,nim,temp;
        int occ = 0;

        // check occ
        for (i = 0 ; i < listLength(l1) ; i++){
            for (j = 0 ; j < listLength(l2) ; j++){
                if (ELMT(l1,i) == ELMT(l2,j)){
                    nim = ELMT(l1,i);
                    insertLast(&l3,nim);
                    occ++;
                }
            }
        }
        printf("%d\n",occ);
        printList(l3);
        printf("\n");
    }
    return 0;
}