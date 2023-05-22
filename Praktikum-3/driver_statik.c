#include <stdio.h>
#include "liststatik.c"

int main()
{
    ListStatik l;
    readList(&l);
    printList(l);
    int length = listLength(l);
    printf("\nLength: %d\n", length);

    // insert first
    int x = 10;
    insertFirst(&l, x);
    printList(l);
    length = listLength(l);
    printf("\nLength: %d\n", length);

    // insert last
    x = 20;
    insertLast(&l, x);
    printList(l);
    length = listLength(l);
    printf("\nLength: %d\n", length);

    // insert at
    x = 30;
    int i = 2;
    insertAt(&l, x, i);
    printList(l);
    length = listLength(l);
    printf("\nLength: %d\n", length);


    // delete first
    printf("\nDelete first\n");
    deleteFirst(&l, &x);
    printList(l);
    length = listLength(l);
    printf("\nLength: %d\n", length);

    // delete last
    printf("\nDelete last\n");
    deleteLast(&l, &x);
    printList(l);
    length = listLength(l);
    printf("\nLength: %d\n", length);

    // delete at
    printf("\nDelete at\n");
    i = 5;
    deleteAt(&l, &x, i);
    printList(l);
    length = listLength(l);
    printf("\nLength: %d\n", length);

    return 0;
}