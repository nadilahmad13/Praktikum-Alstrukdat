#include "listdin.h"
#include <stdio.h>

int main()
{
    ListDin L1, L2, L3;
    int n1, n2;
    CreateListDin(&L1, 100000);
    readList(&L1);
    CreateListDin(&L2, 100000);
    readList(&L2);
    CreateListDin(&L3, 200000);

    int idx1 = 0, idx2 = 0;
    while (idx1 < listLength(L1) || idx2 < listLength(L2))
    {
        if (idx1 == listLength(L1))
        {
            insertLast(&L3, ELMT(L2, idx2));
            idx2++;
        }
        else if (idx2 == listLength(L2))
        {
            insertLast(&L3, ELMT(L1, idx1));
            idx1++;
        }
        else
        {
            if (ELMT(L1, idx1) >= ELMT(L2, idx2))
            {
                insertLast(&L3, ELMT(L1, idx1));
                idx1++;
            }
            else
            {
                insertLast(&L3, ELMT(L2, idx2));
                idx2++;
            }
        }
    }
    printList(L3);
    printf("\n");
    return 0;
}