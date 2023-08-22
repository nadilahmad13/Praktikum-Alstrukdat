#include <stdio.h>

void printstar(int n){
    int i;
    for(i = 0; i < n ; i++){
        printf("*");
    }
}

void printspace(int n){
    int i;
    for(i = 0; i < n ; i++){
        printf(" ");
    }
}

int main(){
    // make a diamond shape, input is an odd number
    // input : 5
    // output :
    //     *
    //    ***
    //   *****
    //    ***
    //     *
    int n;
    scanf("%d", &n);
    int i;
    for(i = 0; i < n / 2 + 1; i++){
        printspace(n-i-1);
        printstar(2*i+1);
        printf("\n");
    }
    for(i = n / 2 - 1; i >= 0; i--){
        printspace(n-i-1);
        printstar(2*i+1);
        printf("\n");
    }
}