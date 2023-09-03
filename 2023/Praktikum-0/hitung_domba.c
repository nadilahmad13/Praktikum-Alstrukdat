#include <stdio.h>

int main(){
    int M,N,i;
    scanf("%d %d",&M,&N);
    for (i = 1 ; i <= M ; i++){
        if (i % N == 0){
            printf("happy\n");
        } else {
            printf("%d\n",i);
        }
    }
    return 0;
}