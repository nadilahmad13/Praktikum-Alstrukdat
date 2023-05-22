// Ahmad Nadil
// 13521024
// File "mtime.c"

#include <stdio.h>
#include "time.h"

int main(){
    int N,i;
    long selisih;
    scanf("%d",&N);
    TIME start,end,temp,maxStart,minStart;
    CreateTime(&minStart,23,59,59);
    CreateTime(&maxStart,0,0,0);
    for (i = 0 ; i < N ; i++)
    {
        printf("[%d]\n",i+1);
        BacaTIME(&start);
        BacaTIME(&end);
        
        if (TIMEToDetik(start) > TIMEToDetik(end))
        {
            temp = start;
            start = end;
            end = temp;
        }

        selisih = Durasi(start,end);
        printf("%ld\n",selisih);

        if (TIMEToDetik(start) > TIMEToDetik(maxStart))
        {
            maxStart = start;
        }

        if (TIMEToDetik(end) > TIMEToDetik(maxStart))
        {
            maxStart = end;
        }
        
        if(TIMEToDetik(start) < TIMEToDetik(minStart))
        {
            minStart = start;
        }
        
        if (TIMEToDetik(end) < TIMEToDetik(minStart))
        {
            minStart = end;
        }
    }

    TulisTIME(minStart);
    printf("\n");
    TulisTIME(maxStart);
    printf("\n");

    return 0;
}