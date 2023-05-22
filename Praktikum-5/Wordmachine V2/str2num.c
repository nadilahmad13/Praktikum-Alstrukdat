// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 5 Oktober 2022
// Topik praktikum  : ADT Mesin Kata
// Deskripsi        : File "str2num.c"

#include <stdio.h>
#include "wordmachine.h"

boolean compareString(Word word1, Word word2) {
    // KAMUS
    int i;

    // ALGORITMA
    if (word1.Length != word2.Length) {
        return false;
    }

    for (i = 0; i < word1.Length; i++)
    {
        if (word1.TabWord[i] != word2.TabWord[i]) {
            return false;
        }
    }
    
    return true;
}

Word strToWord(char str[], int len) {
    // KAMUS
    int i;
    Word ret;

    // ALGORITMA
    ret.Length = len;
    for (i = 0; i < len; i++)
    {
        ret.TabWord[i] = str[i];
    }
    
    return ret;
}

int main() {
    // KAMUS
    int i, num;
    boolean needSpace, isNum, printNum;
    Word nol, satu, dua, tiga, empat, lima, enam, tujuh, delapan, sembilan;
    Word sepuluh, sebelas, belas, puluh, seratus, ratus, seribu, ribu;

    // ALGORITMA
    STARTWORD();

    char cnol[50] = "nol";
    nol = strToWord(cnol, 3);

    char csatu[50] = "satu";
    satu = strToWord(csatu, 4);

    char cdua[50] = "dua";
    dua = strToWord(cdua, 3);

    char ctiga[50] = "tiga";
    tiga = strToWord(ctiga, 4);

    char cempat[50] = "empat";
    empat = strToWord(cempat, 5);
    
    char clima[50] = "lima";
    lima = strToWord(clima, 4);

    char cenam[50] = "enam";
    enam = strToWord(cenam, 4);

    char ctujuh[50] = "tujuh";
    tujuh = strToWord(ctujuh, 5);

    char cdelapan[50] = "delapan";
    delapan = strToWord(cdelapan, 7);

    char csembilan[50] = "sembilan";
    sembilan = strToWord(csembilan, 8);

    char csepuluh[50] = "sepuluh";
    sepuluh = strToWord(csepuluh, 7);

    char csebelas[50] = "sebelas";
    sebelas = strToWord(csebelas, 7);

    char cbelas[50] = "belas";
    belas = strToWord(cbelas, 5);

    char cpuluh[50] = "puluh";
    puluh = strToWord(cpuluh, 5);

    char cseratus[50] = "seratus";
    seratus = strToWord(cseratus, 7);

    char cratus[50] = "ratus";
    ratus = strToWord(cratus, 5);

    num = -1;
    while (!endWord) {
        isNum = false;
        printNum = false;

        if (compareString(nol, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 0;
            isNum = true;
        } else if (compareString(satu, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 1;
            isNum = true;
        } else if (compareString(dua, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 2;
            isNum = true;
        } else if (compareString(tiga, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 3;
            isNum = true;
        } else if (compareString(empat, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 4;
            isNum = true;
        } else if (compareString(lima, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 5;
            isNum = true;
        } else if (compareString(enam, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 6;
            isNum = true;
        } else if (compareString(tujuh, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 7;
            isNum = true;
        } else if (compareString(delapan, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 8;
            isNum = true;
        } else if (compareString(sembilan, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 9;
            isNum = true;
        } else if (compareString(sepuluh, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 10;
            isNum = true;
        } else if (compareString(sebelas, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 11;
            isNum = true;
        } else if (compareString(belas, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 10;
            isNum = true;
        } else if (compareString(puluh, currentWord)) {
            num += (10 * (num % 10)) - (num % 10);
            isNum = true;
        } else if (compareString(seratus, currentWord)) {
            if (num == -1) {
                num = 0;
            }
            num += 100;
            isNum = true;
        } else if (compareString(ratus, currentWord)) {
            num += (100 * (num % 100)) - (num % 100);
            isNum = true;
        } else {
            printNum = true;
        }

        if (printNum && num >= 0) {
            if (needSpace) {
                printf(" ");
            }
            printf("%d", num);
            needSpace = true;
            num = -1;
        }
        
        if (!isNum) {
            if (needSpace) {
                printf(" ");
            }

            for (i = 0; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
            
            needSpace = true;
        }        
        
        ADVWORD();
    }

    if (num >= 0)  {
        if (needSpace) {
                printf(" ");
            }
        printf("%d", num);
        needSpace = true;
    }

    printf("\n");
    
    return 0;
}