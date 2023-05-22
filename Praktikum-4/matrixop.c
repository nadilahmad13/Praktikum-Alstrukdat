#include "matrix.c"
#include <stdio.h>

float rowMean(Matrix m, IdxType i){
    int j;
    float sum = 0;
    for (j = 0; j < COL_EFF(m); j++){
        sum += ELMT(m, i, j);
    }
    return sum/COL_EFF(m);
}

float colMean(Matrix m, IdxType j)
{
    int i;
    float sum = 0;
    for (i = 0; i < ROW_EFF(m); i++){
        sum += ELMT(m, i, j);
    }
    
    return sum/ROW_EFF(m);
}

void rowExtremes(Matrix m, IdxType i, ElType *max, ElType *min){
    *max = ELMT(m,i,0);
    *min = *max;
    int j;
    for(j=1;j<COL_EFF(m);j++){
        if (ELMT(m,i,j) > *max){
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j) < *min){
            *min = ELMT(m,i,j);
        }
    }
}

void colExtremes(Matrix m, IdxType j, ElType *max, ElType *min){
    *max = ELMT(m,0,j);
    *min = *max;
    int i;
    for(i=1;i<ROW_EFF(m); i++){
        if (ELMT(m,i,j) > *max){
            *max = ELMT(m,i,j);
        }
        if (ELMT(m,i,j) < *min){
            *min = ELMT(m,i,j);
        }
    }
}

int countValOnRow(Matrix m, IdxType i, ElType val){
    int count = 0;
    int j;
    for(j = 0; j<COL_EFF(m); j++){
        if(ELMT(m,i,j) == val){
            count += 1;
        }
    }
    return count;
}

int countValOnCol(Matrix m, IdxType j, ElType val){
    int count = 0;
    int i;
    for(i = 0; i<ROW_EFF(m); i++){
        if(ELMT(m,i,j) == val){
            count += 1;
        }
    }
    return count;
}

int main(){
    Matrix m;
    readMatrix(&m, 3, 3);

    // print matrix
    displayMatrix(m);

    // count val on row
    int n = countValOnRow(m, 0, 1);
    printf("%d\n",n);
} 