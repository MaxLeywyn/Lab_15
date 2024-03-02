#include "matrix.h"
#include <stdlib.h>
#include <assert.h>


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}


matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}


void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        m->values[i] = NULL;
    }
    m->values = NULL;
    free(m->values);

    m->nRows = 0;
    m->nCols = 0;
}


void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        freeMemMatrix(&ms[i]);
        printf("\n");
    }
    ms = NULL;
    free(ms);
}


void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; ++i) {
        for (int j = 0; j < m->nCols; ++j) {
            scanf("%d", &m->values[i][j]);
        }

    }
}


void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(&ms[i]);
    }
}


void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}


void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}


void swapRows(matrix *m, int i1, int i2) {
    assert(i1 < m->nRows && i2 < m->nRows);
    swap(&m->values[i1], &m->values[i2]);
}