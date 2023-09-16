#include "listdin.h"
#include <stdio.h>

int main()
{
    ListDin L;
    CreateListDin(&L, 100);
    readList(&L);
    sort(&L, true);
    if (listLength(L) == 1)
    {
        printf("%d\n", 0);
    }
    else
    {
        printf("%d\n", ELMT(L, listLength(L) - 1) - ELMT(L, 0) + 1);
    }
    return 0;
}