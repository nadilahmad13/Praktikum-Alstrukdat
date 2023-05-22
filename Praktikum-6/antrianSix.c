// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 6 Oktober 2022
// Topik praktikum  : ADT Queue
// Deskripsi        : File "antrianSix.c"

#include <stdio.h>
#include "queue.h"

int main(){
    int menu, time, val;
    int terlayani = 0;
    int maxtime = -999;
    int mintime = 999;
    float sumtime = 0;
    Queue q;
    int flag = 1;
    CreateQueue(&q);
    while(flag){
        scanf("%d",&menu);
        if (menu == 1){
            scanf("%d",&time);
            if (isFull(q)){
                printf("Queue penuh\n");
            }
            else{
                enqueue(&q,time);
            }
        }

        else if (menu == 2){
            if (isEmpty(q)){
                printf("Queue kosong\n");
            }
            else{
                sumtime += HEAD(q);
                if (HEAD(q) > maxtime){
                    maxtime = HEAD(q);
                }
                if (HEAD(q) < mintime){
                    mintime = HEAD(q);
                }
                terlayani++;
                dequeue(&q,&val);
            }
        }

        else if(menu == 0){
            flag = 0;
        }
    }

    printf("%d\n", terlayani);
    if (terlayani > 0){
        printf("%d\n",mintime);
        printf("%d\n",maxtime);
        printf("%.2f\n",sumtime / terlayani);
    }
    else{
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
    }

    return 0;
}