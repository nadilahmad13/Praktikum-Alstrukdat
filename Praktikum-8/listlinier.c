// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 27 Oktober 2022
// Topik praktikum  : ADT Linked List
// Deskripsi        : File "listlinier.c"

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val)
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
{
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    Address p = FIRST(l);
    int i = 0;
    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    int i = 0;
    Address p = FIRST(*l);
    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    int i = 0;
    Address p = FIRST(l);
    while (p != NULL) {
        if (INFO(p) == val) {
            return i;
        }
        p = NEXT(p);
        i++;
    }
    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address p = newNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address loc = FIRST(*l);
            int i = 0;
            while (i < idx - 1) {
                loc = NEXT(loc);
                i++;
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address p = FIRST(*l);
    Address loc = NULL;
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        int i = 0;
        Address loc = FIRST(*l);
        while (i < idx - 1) {
            loc = NEXT(loc);
            i++;
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    Address p = FIRST(l);
    while (p != NULL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NULL) {
            printf(",");
        }
    }
    printf("]");
}

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int len = 0;
    Address p = FIRST(l);
    while (p != NULL) {
        len++;
        p = NEXT(p);
    }
    return len;
}
/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) 
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    List l3;
    CreateList(&l3);
    Address p = l1;
    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    Address now;
    boolean flag = false;
    now = L;
    while(now->next != NULL && !flag){
        if(now==P){
            flag = true;
        }
        now = now->next;
    }
    return flag;
}

Address searchPrec(List L, ElType X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    if(isEmpty(L) || length(L) == 1){
        return NULL;
    }
    Address p = L;
    Address previous;
    while(p != NULL && INFO(p)!= X){
        previous = p;
        p = NEXT(p);
    }
    if(p == NULL){
        return NULL;
    }
    else{
        return previous;
    }
}

/*** Prekondisi untuk Max/Min : List tidak kosong ***/
ElType max(List l)
/* Mengirimkan nilai info(P) yang maksimum */
{
    int maksimum;
    Address p = l;
    maksimum = p->info;
    while(p != NULL){
        if(INFO(p) > maksimum){
            maksimum = INFO(p);
        }
        p = NEXT(p);
    }
    return maksimum;
}

Address adrMax(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    int maksimum = max(l);
    Address p = l;
    while (p != NULL && INFO(p) != maksimum){
        p = NEXT(p);
    }
    return p;
}

ElType min(List l)
/* Mengirimkan nilai info(P) yang minimum */
{
    int minimum;
    Address p = l;
    minimum = INFO(p);
    while (p != NULL){
        if (INFO(p) < minimum){
            minimum = INFO(p);
        }
        p = NEXT(p);
    }
    return minimum;
}



Address adrMin(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    int minimum = min(l);
    Address p = l;
    while(p != NULL && INFO(p) != minimum){
        p = NEXT(p);
    }
    return p;
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    Address p = *l;
    int value;
    while(p != NULL){
        deleteFirst(l, &value);
        p = NEXT(p);
    }
    *l = NULL;
}

void copyList(List *l1, List *l2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    *l2 = *l1;
}


void inverseList(List *l)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    if(!isEmpty(*l)){
        int n = length(*l);
        int i;
        Address p = *l;
        Address prev;
        Address last;
        while(NEXT(p)!= NULL){
            p = NEXT(p);
        }
        last = p;
        while (p != *l){
            prev = *l;
            while(NEXT(prev) != p){
                prev = NEXT(prev);
            }
            NEXT(p) = prev;
            p = prev;
        }
        NEXT(p) = NULL;
        *l = last;
    }
}
void splitList(List *l1, List *l2, List l)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
{
    CreateList(l1);
    CreateList(l2);
    int half = length(l) / 2;
    int cnt = 0;
    Address p = l;
    while(p != NULL){
        if(cnt < half){
            insertLast(l1, INFO(p));
        }
        else{
            insertLast(l2, INFO(p));
        }
        cnt++;
        p = NEXT(p);
    }
}