#include <stdio.h>
#include "time.c"   

int main()
{
    // second to time
    long N = 86401;
    time T = secondsToTime(N);
    TulisTIME(T);
}