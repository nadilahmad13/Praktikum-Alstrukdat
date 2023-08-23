#include <stdio.h>

int *value(void) {
    int i = 3;
    return &i;
}

void callme (void){
    int x = 35;
}

int main(void) {
    int *ip;
    ip = value(); // ip = 3
    printf("*ip = %d\n", *ip);
    callme(); // 
    printf("*ip = %d\n", *ip);
}