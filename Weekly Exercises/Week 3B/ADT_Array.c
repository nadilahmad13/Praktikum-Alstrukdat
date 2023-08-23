#include <stdio.h>

void isSimetris(int l[], int n){
    int i = 0, j = n-1;
    while(i < j){
        if(l[i] != l[j]){
            printf("Array tidak simetris");
            return;
        }
        i++;
        j--;
    }
    printf("Array simetris");
}

// int plusTab(int l1[], int l2[]){
//     int i,n;
//     n = sizeof(l1)/sizeof(l1[0]);
//     int l3[100];
//     for (i = 0; i < n; i++){
//         l3[i] = l1[i] + l2[i];
//     }
//     return l3;
// }

int length(int l[]){
    int i = 0;
    while (l[i] != '\0'){
        i++;
    }
    return i;
}

int main()
{
    int li[100] = {1,2,3,4,5,4,3,2,1};
    int n = length(li);
    isSimetris(li, n);
}