#include "time.h"

void CreateTime(time *t, int h, int m, int s)
{
    HOURS(*t) = h;
    MINUTES(*t) = m;
    SECONDS(*t) = s;
}

boolean isTimeValid (int h, int m, int s)
{
    return (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60);
}

void readTime (time *t)
{
    int h,m,s;
    while(!isTimeValid(h,m,s))
    {
        printf("Masukkan jam (0-23): ");
        scanf("%d",&h);
        printf("Masukkan menit (0-59): ");
        scanf("%d",&m);
        printf("Masukkan detik (0-59): ");
        scanf("%d",&s);
    }
    CreateTime(t,h,m,s);
}

void displayTime (time t)
{
    printf("%02d:%02d:%02d\n",HOURS(t),MINUTES(t),SECONDS(t));
}

int timeToSeconds (time t)
{
    return (HOURS(t)*3600 + MINUTES(t)*60 + SECONDS(t));
}

time secondsToTime (int n) 
{
    int h,m,s,sisa; time t1;
    n = n % 86400;
    h = n / 3600;
    sisa = n % 3600;
    m = sisa / 60;
    s = sisa % 60;
    CreateTime(&t1,h,m,s);
    return t1;
}