#include <stdio.h>
#include "tokenmachine.h"
#include "tokenmachine.c"
#include "charmachine.c"
#include "charmachine.h"

int main() {
    /* KAMUS */

    /* ALGORITMA */
    startToken();

    while (!endToken) {
        printf("<");

        printf("\'");
        printf("%c", currentToken.tkn);
        printf("\'");

        printf(",");

        printf("%d", currentToken.val);
        
        printf(">\n");
        advToken();
    }
}