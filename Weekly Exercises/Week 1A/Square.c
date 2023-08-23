#include <stdio.h>

int square (int x){
    return x * x;
}

int main(){
    int a = 12;
    int sq = square(a);
    printf("%d² = %d\n", a, sq);
}