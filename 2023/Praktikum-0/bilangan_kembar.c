#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);

    for (int i = a ; i <= b ; i++){
        int temp = i;
        int rev = 0;
        while (temp > 0){
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        if (rev == i) printf("%d\n",i);
    }
    return 0;
}