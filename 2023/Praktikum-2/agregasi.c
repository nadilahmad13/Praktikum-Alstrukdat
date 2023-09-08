#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik L;
    readList(&L);
    int x;
    scanf("%d", &x);

    // 1. Sort dan Print
    sortList(&L, true);
    printList(L);
    printf("\n");

    // 2. Average
    float sum = 0;
    for (int i = 0; i < listLength(L); i++)
    {
        sum += ELMT(L, i);
    }
    printf("Average: %.2f\n", sum / listLength(L));

    // Find x
    if (indexOf(L, x) != IDX_UNDEF)
    {
        printf("%d\n", indexOf(L, x));
        ElType max,min;
        extremeValues(L, &max, &min);
        if (x == max)
        {
            printf("X maksimum\n");
        }
        if (x == min)
        {
            printf("X minimum\n");
        }
        if (listLength(L) % 2 == 0 && x == ELMT(L, (listLength(L) / 2)-1))
        {
            printf("X median\n");
        }
        if (listLength(L) % 2 == 1 && x == ELMT(L, (listLength(L) / 2)))
        {
            printf("X median\n");
        }
    }
    else
    {
        printf("%d tidak ada\n", x);
    }
    return 0;
}