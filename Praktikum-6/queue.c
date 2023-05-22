// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 5 Oktober 2022
// Topik praktikum  : ADT Queue
// Deskripsi        : File "queue.c"

#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{  
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return(IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITY-1);
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (isEmpty(q))
        return 0;
    else if (IDX_TAIL(q) >= IDX_HEAD(q))
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    else
        return CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else {
        if (IDX_TAIL(*q) == CAPACITY - 1){
            IDX_TAIL(*q) = 0;
        }
        else {
            IDX_TAIL(*q)++;
        }
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
{
    *val = HEAD(*q);
    if (length(*q) == 1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else {
        if (IDX_HEAD(*q) == CAPACITY - 1){
            IDX_HEAD(*q) = 0;
        }
        else {
            IDX_HEAD(*q)++;
        }
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    int i;
    if (isEmpty(q))
        printf("[]\n");
    else {
        printf("[");
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i+1)%CAPACITY){
            printf("%d,", q.buffer[i]);
        }
        printf("%d]\n", q.buffer[i]);
    }

}