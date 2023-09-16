#include "listdin.h"
#include <stdio.h>

void deleteAt(ListDin *L, int idx)
{
    // delete element at index idx
    int i;
    for (i = idx; i < listLength(*L) - 1; i++)
    {
        ELMT(*L, i) = ELMT(*L, i + 1);
    }
    NEFF(*L)
    --;
}

void deleteEl(ListDin *L, int num)
{
    // delete element that is less than num
    int i = 0;
    while (i < listLength(*L))
    {
        if (ELMT(*L, i) < num)
        {
            deleteAt(L, i);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int C, Q;
    ListDin L;
    scanf("%d", &C);
    CreateListDin(&L, C);
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++)
    {
        int query;
        scanf("%d", &query);
        if (query == 1)
        {
            int num;
            scanf("%d", &num);
            deleteEl(&L, num);
            insertLast(&L, num);
        }
        else if (query == 2)
        {
            printf("%d\n", listLength(L));
            printList(L);
            printf("\n");
        }
    }

    return 0;
}