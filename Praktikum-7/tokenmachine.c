#include "boolean.h"
#include "tokenmachine.h"
#include "charmachine.c"


/* Token Machine State */
boolean endToken;
Token currentToken;
boolean isToken(char c);
boolean isInt(char c);

void ignoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK){
        ADV();
    }
}
void startToken()
/* I.S. : currentChar sembarang 
   F.S. : endToken = true, dan currentChar = MARK; 
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */
{
    START();
    ignoreBlank();
    if (currentChar == MARK){
        endToken = true;
    }
    else{
        endToken = false;
        salinToken();
    }
}
void advToken()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true		  
   Proses : Akuisisi kata menggunakan procedure salinToken */
{
    ignoreBlank();
    if(currentChar == MARK){
        endToken = true;
    }
    else{
        salinToken();
        ignoreBlank();
    }
}
void salinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
{
    int i = 0;
    currentToken.val = 0;
    while(currentChar != MARK && currentChar != BLANK){
        if (i < CAPACITY){
            if(isInt(currentChar)){
                currentToken.tkn = 'b';
                currentToken.val = currentToken.val * 10 + (currentChar - 48);
            }
            else if(isToken(currentChar)){
                currentToken.tkn = currentChar;
                currentToken.val = -1;
            }
        }
        ADV();
        i++;
    }
}

boolean isToken(char c){
    int i;
    char tokens[] = "+-*/^";
    boolean flag = false;
    for(i = 0; i < 5; i++){
        if(c == tokens[i]){
            flag = true;
        }
    }
    return flag;
}

boolean isInt(char c){
    int i;
    char numbers[] = "0123456789";
    boolean flag = false;
    for(i = 0; i < 10; i++){
        if(c == numbers[i]){
            flag = true;
        }
    }
    return flag;
}