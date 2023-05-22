#include <stdio.h>
#include "matrix.c"

int main(){
    Matrix m;
    readMatrix(&m,3,3);
    RotateMat(&m);
    displayMatrix(m);
}