// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 20 Oktober 2022
// Topik praktikum  : ADT Stack
// Deskripsi        : File "bigint.c"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

int charToNum(char c) {
    return (c - 48);
}

char numToChar(int n) {
    return (n + 48);
}

boolean isGreater(char arr1[100], char arr2[100]){
    int temp1, temp2;
    if (strlen(arr1) > strlen(arr2)) {
        return true;
    }
    else if (strlen(arr1) < strlen(arr2)) {
        return false;
    }
    else {
        int idx = 0; 
        while (idx < strlen(arr1)) {
            if (arr1[idx] > arr2[idx]) {
                return true;
            }
            else if (arr1[idx] < arr2[idx]) {
                return false;
            }
            idx++;
        }
    }
    return true;
}

int main() {
    Stack S1, S2, Smin;
    int val1, val2, result;
    int i = 0;
    int j = 0;
    char arr1[100], arr2[100];
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&Smin);
    scanf("%s", &arr1);
    while (arr1[i] != '\0') {
        if (charToNum(arr1[i]) >= 0) {
            Push(&S1,charToNum(arr1[i]));
        }
        i++;
    }
    scanf("%s", &arr2);
    while (arr2[j] != '\0'){
        if (charToNum(arr2[j]) >= 0) {
            Push(&S2, charToNum(arr2[j]));
        }
        j++;
    }
    int sisa = 0;
    if (isGreater(arr1, arr2)) {
        while (!IsEmpty(S2)) {
            Pop(&S1, &val1);
            Pop(&S2, &val2);
            result = val1 - val2 + sisa;
            if (result < 0) {
                sisa = -1; 
                result += 10;
                Push(&Smin, result);
            }
            else {
                sisa = 0;
                Push(&Smin, result);
            }
        }
        while (!IsEmpty(S1)) {
            Pop(&S1, &val1);
            result =  val1 + sisa;
            if (result < 0) {
                sisa = -1; 
                result += 10;
                Push(&Smin, result);
            }
            else {
                sisa = 0; 
                Push(&Smin, result);
            }
        }
        while (InfoTop(Smin) == 0 && Top(Smin) > 0) {
            Pop(&Smin, &val1);
        }
    }
    else {
        while (!IsEmpty(S1)) {
            Pop(&S1, &val1);
            Pop(&S2, &val2);
            result = val2 - val1 + sisa;
            if (result < 0) {
                sisa = -1; 
                result += 10; 
                Push(&Smin, result);
            }
            else {
                sisa = 0; 
                Push(&Smin, result);
            }
        }
        while (!IsEmpty(S2)) {
            Pop(&S2, &val2);
            result = val2 + sisa; 
            if (result < 0) {
                sisa = -1; 
                result += 10; 
                Push(&Smin, result);
            }
            else {
                sisa = 0; 
                Push(&Smin, result);   
            }
        }
        while (InfoTop(Smin) == 0 && Top(Smin) > 0) {
            Pop(&Smin, &val1);
        }
        if (InfoTop(Smin) != 0) {
            Pop(&Smin, &val2);
            val2 *= -1; 
            Push(&Smin, val2);
        }
    }
    int tempMinus;
    while (!IsEmpty(Smin)) {
        Pop(&Smin, &tempMinus);
        printf("%d", tempMinus);
    }
    printf("\n");
}