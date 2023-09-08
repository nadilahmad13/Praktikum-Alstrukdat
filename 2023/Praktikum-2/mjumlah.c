#include <stdio.h>
#include "liststatik.h"

int poww(int num, int pow)
{
    int res = 1;
    for (int i = 0; i < pow; i++)
    {
        res *= num;
    }
    return res;
}

int main()
{
    ListStatik L1, L2, L3;
    readList(&L1);
    readList(&L2);
    CreateListStatik(&L3);

    int sum = 0;
    for (int i = 0; i < listLength(L1); i++)
    {
        sum += ELMT(L1, i) * poww(10, listLength(L1) - i - 1);
    }

    for (int i = 0; i < listLength(L2); i++)
    {
        sum += ELMT(L2, i) * poww(10, listLength(L2) - i - 1);
    }

    while (sum > 0)
    {
        insertFirst(&L3, sum % 10);
        sum /= 10;
    }

    printList(L3);
    printf("\n");
    return 0;
}