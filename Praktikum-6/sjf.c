// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 5 Oktober 2022
// Topik praktikum  : ADT Queue
// Deskripsi        : File "sjf.c"

#include <stdio.h>
#include "prioqueuetime.h"

int main()
{
    int i, n;
    int runTime = 0;
    int currentTime = 0;
    infotype x, val;
    PrioQueueTime Q;
    
    scanf("%d", &n);
    MakeEmpty(&Q, n + 1);
    for (i = 0; i < n; i++) {
        currentTime = i;
        scanf("%d %c", &Time(x), &Info(x));
        Enqueue(&Q, x);
        
        if (currentTime >= runTime) {
            Dequeue(&Q, &val);
            printf("%d %c\n", runTime, Info(val));
            runTime += Time(val);
        }
    }

    while (!IsEmpty(Q)) {
        Dequeue(&Q, &val);
        printf("%d %c\n", runTime, Info(val));
        runTime += Time(val);
    }
    return 0;
}