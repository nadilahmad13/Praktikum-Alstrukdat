#include <stdio.h>

int f (void){
    int s = 1;
    int t = 1;
    int *ps = &s;
    int **pps = &ps;
    int *pt = &t;

    **pps = 2;
    printf("t = %d, s = %d\n", t, s);
    pt = ps;
    printf("t = %d, s = %d\n", t, s);
    *pt = 3;
    printf("t = %d, s = %d\n", t, s);
    t = s;
    printf("t = %d, s = %d\n", t, s);
}

int main(){
    f();
}