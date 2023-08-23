#ifndef TIME_H
#define TIME_H
#include "boolean.h"

#define HOURS(t) (t).hours 
#define MINUTES(t) (t).minutes
#define SECONDS(t) (t).seconds

typedef struct Time{
    int hours;
    int minutes;
    int seconds;
} time;

void CreateTime (time* t, int h, int m, int s);
boolean isTimeValid (int h, int m, int s);
void readTime (time * t);
void displayTime (time t);
int timeToSeconds (time t);
time secondsToTime (int s);

#endif