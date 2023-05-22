// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 22 September 2022
// Topik praktikum  : ADT Matrix
// Deskripsi        : File "submatrix.c"

#include <stdio.h>
#include "matrix.h"

float sumSubmatrix(Matrix m, int startRow, int startCol, int n){
    float sum = 0;
    int i, j;
    for(i=startRow;i<startRow+n;i++){
        for(j=startCol;j<startCol+n;j++){
            if (ELMT(m,i,j) != 0){
                sum++;
            }
        }
    }
    return sum;
}

int main(){
    int t;
    int N;
    int sub;
    int tempsum;
    int maxsum;
    int startRow, startCol;
    Matrix m, ans;
    int daerah = 0;
    int daerahNow = 0;

    maxsum = 0;
    scanf("%d", &N);
    scanf("%d", &sub);
    readMatrix(&m, N, N);
    createMatrix(sub, sub, &ans);
    for(startRow=0; startRow<ROW_EFF(m)-sub+1; startRow++){ 
        for(startCol=0; startCol<COL_EFF(m)-sub+1;startCol++){
        	daerahNow++;
            tempsum = sumSubmatrix(m, startRow, startCol, sub);
            if (tempsum>maxsum){
                maxsum = tempsum;
                daerah = daerahNow;
            }   
        }
    }
    printf("%d\n", daerah);
}