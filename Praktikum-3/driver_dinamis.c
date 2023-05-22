#include <stdio.h>
#include "listdin.c"

int main(){
    ListDin l;
    printf("L1\n");
    readList(&l);
    printList(l);
    printf("\n");
    
    ListDin l2;
    printf("L2\n");
    readList(&l2);
    printList(l2);
    printf("\n");

    // plus minus list
    printf("plus minus list\n");
    ListDin l3;
    plusMinusList(l, l2, true);
    printList(l3);
    printf("\n");

    // minus plus list
    printf("minus plus list\n");
    ListDin l4;
    plusMinusList(l, l2, false);
    printList(l4);
    printf("\n");

    // indexOf
    int x = 3;
    int idx = indexOf(l, x);
    printf("Index of %d is %d\n", x, idx);


    // extremeValues
    int max, min;
    extremeValues(l, &max, &min);
    printf("Max: %d, Min: %d\n", max, min);

    // sort
    printf("Asc\n");
    sort(&l,true);
    printList(l);
    printf("\nDesc\n");
    sort(&l,false);
    printList(l);
    printf("\n");
    
    // insertLast
    printf("Insert Last\n");
    insertLast(&l, 999);
    printList(l);
    printf("\n");

    // deleteLast
    printf("Delete Last\n");
    ElType e = 999;
    deleteLast(&l, &e);
    printList(l);
    printf("\n");

    // expandList
    printf("Expand List\n");
    expandList(&l, 5);
    printList(l);
    printf("\n");

    // shrinkList
    printf("Shrink List\n");
    shrinkList(&l, 5);
    printList(l);
    printf("\n");
    
    return 0;
}