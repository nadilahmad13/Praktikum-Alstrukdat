#include <stdio.h>

void swap (int*xp, int*yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
} 

int main(){
    int x = 5;
    int y = 10;
    printf("x=%d,y=%d\n",x,y);
    swap(&x,&y);
    printf("x=%d,y=%d\n",x,y);
}