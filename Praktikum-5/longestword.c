// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 29 September 2022
// Topik praktikum  : ADT Mesin Kata
// Deskripsi        : File "longestword.c"

#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

// State Machine
boolean EndWord;
Word currentWord;


int main()
{
    int longest = 0;
    STARTWORD();
    while(!EndWord){
        if(currentWord.Length >= longest){
            longest = currentWord.Length;
        }
        ADVWORD();
    }
    printf("%d\n",longest);

    return 0;
}