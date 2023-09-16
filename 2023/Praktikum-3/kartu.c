#include "listdin.h"
#include <stdio.h>

void deleteFirst(ListDin *L, ElType *X)
{
    int i;
    *X = ELMT(*L, 0);
    for (i = 0; i < listLength(*L) - 1; i++)
    {
        ELMT(*L, i) = ELMT(*L, i + 1);
    }
    NEFF(*L)--;
}

int main()
{
    ListDin L1, L2, L3;
    int n1, n2;
    CreateListDin(&L1, 100000);
    readList(&L1);
    CreateListDin(&L2, 100000);
    readList(&L2);
    CreateListDin(&L3, 300000);
    while (!isEmpty(L1) || !isEmpty(L2))
    {
        ElType temp;
        if (isEmpty(L1))
        {
            insertLast(&L3, ELMT(L2, 0));
            deleteFirst(&L2, &temp);
        }
        else if (isEmpty(L2))
        {
            insertLast(&L3, ELMT(L1, 0));
            deleteFirst(&L1, &temp);
        }
        else
        {
            if (ELMT(L1, 0) >= ELMT(L2, 0))
            {
                insertLast(&L3, ELMT(L1, 0));
                deleteFirst(&L1, &temp);
            }
            else
            {
                insertLast(&L3, ELMT(L2, 0));
                deleteFirst(&L2, &temp);
            }
        }
    }
    printList(L3);
    printf("\n");

    return 0;
}