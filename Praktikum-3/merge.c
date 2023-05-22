// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 14 September 2022
// Topik praktikum  : ADT List Statik dan Dinamik
// Deskripsi        : File ".c"

#include <stdio.h>
#include <stdlib.h>
#include "listdin.c"

int main(){
    ListDin l1,l2,l3;
    CreateListDin(&l1,200);
    CreateListDin(&l2,200);
    CreateListDin(&l3,400);

    readList(&l1);
    readList(&l2);

    sort(&l1,true);
    sort(&l2,true);

    int i,j;
    for (i = 0 ; i < listLength(l1) ; i++){
        if (indexOf(l3,ELMT(l1,i)) == IDX_UNDEF){ 
            insertLast(&l3,ELMT(l1,i));
        }
    }

    for (i = 0 ; i < listLength(l2) ; i++){
        if (indexOf(l3,ELMT(l2,i)) == IDX_UNDEF){
            insertLast(&l3,ELMT(l2,i));
        }
    }

    sort(&l3,true);
    int len = listLength(l3);
    printf("%d\n",len);
    printList(l3);
    printf("\n");

    return 0;
}