// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 17 November 2022
// Topik praktikum  : Queue dan Stack dengan struktur berkait
// Deskripsi        : File "butak.c"

#include <stdio.h>
#include <stdlib.h>
#include "queuelinked.h"
#include "charmachine.h"

boolean isElHomogen(Queue q){
    Address P = ADDR_HEAD(q);
    int x = INFO(P); 
    while (P != NULL) {
        if (INFO(P) != x) {
            return false;
        }
        P = NEXT(P);
    }
    return true;
}

int main(){
    Queue qSandwich;
    Queue qMahasiswa;
    Queue nomorMahasiswa;
    CreateQueue(&qSandwich);
    CreateQueue(&qMahasiswa);
    CreateQueue(&nomorMahasiswa);
    boolean koma = false;
    START();
    int count = 0;
    while (currentChar != ',') {
        if (currentChar == 'B') {
            enqueue(&qMahasiswa, 0);
        } 
        else if (currentChar == 'K') {
            enqueue(&qMahasiswa, 1);
        }
        count++;
        enqueue(&nomorMahasiswa, count);
        ADV();
    }
    ADV();
    while (!EOP) {
        if (currentChar == 'B') {
            enqueue(&qSandwich, 0);
        }
        else if (currentChar == 'K') {
            enqueue(&qSandwich, 1);
        }
        ADV();
    }
    int i,temp,shape;
    while (!isEmpty(qSandwich) && !(isElHomogen(qMahasiswa) && HEAD(qMahasiswa) != HEAD(qSandwich))) {
        if (HEAD(qMahasiswa) == HEAD(qSandwich)){
            dequeue(&qMahasiswa,&shape);
            dequeue(&qSandwich,&shape);
            dequeue(&nomorMahasiswa,&temp);
            if (shape == 0){
                printf("%d -> bulat\n",temp);
            }
            else{
                printf("%d -> kotak\n",temp);
            }
        }
        else{
            dequeue(&qMahasiswa,&shape);
            enqueue(&qMahasiswa,shape);
            dequeue(&nomorMahasiswa,&temp);
            enqueue(&nomorMahasiswa,temp);
        }
    }
    printf("%d\n",length(qSandwich));
    return 0;
}