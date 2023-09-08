#include <stdio.h>
#include "liststatik.h"

int main(){
    // inisiasi
    ListStatik L1, L2, L3;
    readList(&L1);
    readList(&L2);
    CreateListStatik(&L3);

    for (int i = 0 ; i < listLength(L1) ; i++)
    {
        insertLast(&L3, ELMT(L1, i));
    }

    for (int i = 0 ; i < listLength(L2) ; i++)
    {
        insertLast(&L3, ELMT(L2, i));
    }

    sortList(&L3, true);

    printList(L3);
    printf("\n");
    return 0;
}