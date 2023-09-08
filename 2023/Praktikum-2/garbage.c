#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik rumah, perjalanan;
    readList(&rumah);
    readList(&perjalanan);
    insertFirst(&perjalanan, 0);
    int sum = 0;
    for (int i = 1 ; i <= 3 ; i++)
    {
        int idx = 0;
        // printList(rumah);
        // printf("\n");
        while(indexOf(rumah, i) != IDX_UNDEF)
        {
            // printf("%d %d\n", ELMT(rumah, idx), ELMT(perjalanan, idx));
            sum += ELMT(perjalanan, idx);
            if (ELMT(rumah, idx) == i)
            {
                sum += 1;
                ELMT(rumah, idx) = 0;
            }
            idx++;
            if (indexOf(rumah, i) == IDX_UNDEF)
            {
                // printf("%d\n", idx);
                for (int i = 0 ; i < idx ; i ++)
                {
                    sum += ELMT(perjalanan, i);
                }
            }
        }
        // printf("%d\n", sum);
    }

    printf("%d\n", sum);
}

// 5
// 1 2 1 1 0
// 4
// 2 4 3 9
