#include "node.h"
#include <stdlib.h>

Address newNode (ElType val){
    Address p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

int main(){
    Address p1,p2;

    p1 = newNode(9);
    p2 = newNode(5);

    NEXT(p1) = p2;

    printf("%d %d", INFO(p1), INFO(p2));
}