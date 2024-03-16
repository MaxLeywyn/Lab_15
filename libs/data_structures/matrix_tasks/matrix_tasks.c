#include "matrix_tasks.h"
#include <stdlib.h>
#include <assert.h>


void sortRowsByMinAndMaxElement(matrix *m) {
    int n1 = getMaxValuePos(*m).rowIndex;
    int n2 = getMinValuePos(*m).rowIndex;
    swapRows(m, n1, n2);
}

int getMax(int *a, int n){
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (max<a[i])
            max=a[i];
    }
    return max;
}


void sortRowsByMinElement(matrix *m){
    int a[m->nRows];

    for (int i = 0; i < m->nRows; ++i) {
        a[i] = getMax(m->values[i],m->nCols);
    }

    for (int i = 0; i < m->nRows; ++i) {
        for (int j = i+1; j < m->nRows; ++j) {
            if(a[i]>=a[j]){
                swapRows(m,i,j);
            }
        }
    }
}




//Lab_16