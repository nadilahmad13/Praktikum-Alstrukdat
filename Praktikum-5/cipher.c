#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include <stdio.h>

int main(){
    Word temp;
    int i;
    startWord();
    int geser = currentWord.Length % 26;
    for(i = 0; i < currentWord.Length; i++){
        temp.TabWord[i] = currentWord.TabWord[i] + geser;
        if(temp.TabWord[i] > 90){
            temp.TabWord[i] -= 26;
        }
        printf("%c", temp.TabWord[i]);
    }
    advWord();
    while(!EndWord){
        printf(" ");
        int len = currentWord.Length;
        temp.Length = len;
        for(i = 0; i < len; i++){
            temp.TabWord[i] = currentWord.TabWord[i] + geser;
            if(temp.TabWord[i] > 90){
                temp.TabWord[i] -= 26;
            }
            printf("%c", temp.TabWord[i]);
        }
        advWord();
    }
    printf(".\n");
}