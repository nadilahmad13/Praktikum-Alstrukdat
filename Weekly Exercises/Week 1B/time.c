#include "time.h"

int difference(time start, time end){
    int startSec, endSec;
    startSec = getHours(start)*60*60 + getMinutes(start)*60 + getSeconds(start);
    endSec = getHours(end)*60*60 + getMinutes(end)*60 + getSeconds(end);
    return endSec - startSec;
}