#include "listdin.h"
#include <stdio.h>

int main()
{
    ListDin L;
    CreateListDin(&L, 0);
    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++)
    {
        int tipe;
        scanf("%d", &tipe);
        if (tipe == 1)
        {
            int x;
            scanf("%d", &x);
            if (CAPACITY(L) == 0)
            {
                expandList(&L, 1);
            }
            else if (isFull(L))
            {
                expandList(&L, (CAPACITY(L) * 2) - CAPACITY(L));
            }
            insertLast(&L, x);
        }
        else if (tipe == 2)
        {
            ElType temp;
            deleteLast(&L, &temp);
            int cap = CAPACITY(L) / 2;
            if (listLength(L) <= CAPACITY(L) / 2)
            {
                shrinkList(&L, cap);
            }
        }
        else if (tipe == 3)
        {
            printf("%d ", CAPACITY(L));
            printList(L);
            printf("\n");
        }
    }

    return 0;
}