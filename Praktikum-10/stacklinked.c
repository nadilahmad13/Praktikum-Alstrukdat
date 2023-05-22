// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 6 November 2022
// Topik praktikum  : Queue dan Stack dengan struktur berkait
// Deskripsi        : File "stacklinked.c"

#include <stdio.h>
#include <stdlib.h>
#include "stacklinked.h"

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   
{
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s)
/* Mengirim true jika Stack kosong: TOP(s) = NIL */
{
    return ADDR_TOP(s) == NULL;
}

int length(Stack s)
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */
{
    int count = 0;
    Address p = ADDR_TOP(s);
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

void CreateStack(Stack *s)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */
{
    ADDR_TOP(*s) = NULL;
}

void DisplayStack(Stack s)
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */
{
    Address p = ADDR_TOP(s);
    printf("[");
    while (p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) {
            printf(",");
        }
    }
    printf("]");
}

void push(Stack *s, ElType x)
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */
{
    Address p = newNode(x);
    if (p != NULL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x)
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
{
    Address p = ADDR_TOP(*s);
    *x = TOP(*s);
    ADDR_TOP(*s) = NEXT((ADDR_TOP(*s)));
    NEXT(p) = NULL;
    free(p);
}