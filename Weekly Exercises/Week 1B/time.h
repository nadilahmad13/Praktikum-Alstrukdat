// Modul ADT Time
#ifndef TIME_H
#define TIME_H

typedef struct Time {
    int hours;
    int minutes;
    int seconds;
} time;

void CreateTime(time *t, int h, int m, int s);
int getHours(time t);
int getMinutes(time t);
int getSeconds(time t);
int difference(time start, time end);

#endif // TIME_H