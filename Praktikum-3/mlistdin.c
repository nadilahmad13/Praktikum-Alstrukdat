#include <stdio.h>
#include "listdin.c"

int main(){
    int Cap, q, i, menu, num;
    ListDin l;
    scanf("%i", &Cap);
    CreateListDin(&l, Cap);
    readList(&l);
    scanf("%i", &q);
    for(i = 0; i<q; i++){
        int flag = 1;
        scanf("%i", &menu);
        if (menu != 4){
            scanf("%i", &num);
        }
        if (menu == 1){
            if(isFull(l)){
                printf("list sudah penuh\n");
                flag = 0;
            }
            else{
                insertLast(&l, num);
            }
        }
        else if (menu == 2){
            expandList(&l, num);
        }
        else if (menu == 3){
            if(num > CAPACITY(l)){
                printf("list terlalu kecil\n");
                flag = 0;
            }
            else{
                shrinkList(&l, num);
            }
        }
        else if (menu == 4){
            compressList(&l);
        }
        if (flag){
            printf("%i ", CAPACITY(l)); 
            printList(l); 
            printf("\n");
        }
    }
}