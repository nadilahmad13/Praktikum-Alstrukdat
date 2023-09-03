#include <stdio.h>

int main(){
    int max1 = 0, max2 = 0, num;
    for (int i = 0 ; i < num ; i++){
        if (num > max1){
            max2 = max1;
            max1 = num;
        } else if (num > max2){
            max2 = num;
        }
    }
    printf("%d\n",max2);
    return 0;
}