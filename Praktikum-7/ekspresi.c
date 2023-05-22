// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 20 Oktober 2022
// Topik praktikum  : ADT Stack
// Deskripsi        : File "ekspresi.c"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
#include "wordmachine.h"

boolean isOperator(char *c){
    return (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/' || c[0] == '^');
}

int evaluate(int a, int b, char t)
{
    if (t == '+')
    {
        return a + b;
    }
    else if (t == '-')
    {
        return a - b;
    }
    else if (t == '*')
    {
        return a * b;
    }
    else if (t == '/')
    {
        return a / b;
    }
    else if (t == '^')
    {
        return pow(a, b);
    }
}

int main()
{
    Stack S;
    CreateEmpty(&S);
    STARTWORD();
    int temp;
    int val1, val2;
    int i = 0;
    while (!endWord){
        if (!isOperator(currentWord.TabWord)){
            temp = 0;
            for (i = 0; i < currentWord.Length; i++){
                temp = temp * 10 + (currentWord.TabWord[i] - 48);
            }
            Push(&S, temp);
            printf("%d\n", temp);
        }
        else{
            Pop(&S, &val2);
            Pop(&S, &val1);
            printf("%d %c %d\n", val1, currentWord.TabWord[0], val2);
            Push(&S, evaluate(val1, val2, currentWord.TabWord[0]));
            printf("%d\n", InfoTop(S));
        }
        ADVWORD();
    }
    if (IsEmpty(S)){
        printf("Ekspresi kosong\n");
    } else {
        Pop(&S, &temp);
        printf("Hasil=%d\n", temp);
    }
    return 0;
}