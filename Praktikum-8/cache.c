// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 27 Oktober 2022
// Topik praktikum  : ADT Linked List
// Deskripsi        : File "cache.c"

#include <stdio.h>
#include "listlinier.h"

int main(){
    int n;
    scanf("%d", &n);

    int i, x, temp;

    List l;
    CreateList(&l);

    int q;
    scanf("%d", &q);
    
    float hit_counter = 0;

    if (q > 0){
        for (i = 0 ; i < q ; i ++){
            scanf("%d", &x);
            if (isEmpty(l)){
                if (length(l) < n)
                {
                    insertFirst(&l, x);
                }
                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else if (indexOf(l, x) != IDX_UNDEF){
                hit_counter++;
                deleteAt(&l, indexOf(l, x), &temp);
                insertFirst(&l, x);
                printf("hit ");
                displayList(l);
                printf("\n");
            }
            else if (length(l) == n){
                deleteLast(&l, &temp);
                insertFirst(&l, x);

                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else{
                insertFirst(&l, x);
                printf("miss ");
                displayList(l);
                printf("\n");
            }
	    }

        double ratio = hit_counter / q;
        printf("hit ratio: %.2f\n",ratio);
    }

    else{
        printf("hit ratio: %.2f\n",0.00);
    }
    return 0;
}