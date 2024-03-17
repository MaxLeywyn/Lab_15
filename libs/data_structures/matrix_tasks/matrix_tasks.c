#include "matrix_tasks.h"
#include <stdlib.h>
#include <assert.h>


void sortRowsByMinAndMaxElement(matrix *m) {
    int n1 = getMaxValuePos(*m).rowIndex;
    int n2 = getMinValuePos(*m).rowIndex;
    swapRows(m, n1, n2);
}

int getMax(int *a, int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (max < a[i])
            max = a[i];
    }
    return max;
}


void sortRowsByMinElement(matrix *m) {
    int a[m->nRows];

    for (int i = 0; i < m->nRows; ++i) {
        a[i] = getMax(m->values[i], m->nCols);
    }

    for (int i = 0; i < m->nRows; ++i) {
        for (int j = i + 1; j < m->nRows; ++j) {
            if (a[i] >= a[j]) {
                swapRows(m, i, j);
            }
        }
    }
}


void sortColsByMinElement(matrix *m) {
    int a[m->nCols];

    for (int i = 0; i < m->nCols; ++i) {
        int min = INT_MAX;
        for (int j = 0; j < m->nRows; ++j) {
            if (m->values[j][i] < min) {
                min = m->values[j][i];
            }
        }
        a[i] = min;
    }

    for (int i = 0; i < m->nRows; ++i) {
        for (int j = i + 1; j < m->nRows; ++j) {
            if (a[i] > a[j]) {
                swapColumns(m, i, j);
            }
        }
    }
}


matrix mulMatrices(matrix m1, matrix m2) {
    matrix m = getMemMatrix(m2.nRows, m2.nCols);
    int m2_row = 0;
    for (int k = 0; k < m2.nCols; ++k) {
        for (int i = 0; i < m1.nRows; ++i) {
            int el = 0;
            for (int j = 0; j < m2.nRows; ++j) {
                el += m1.values[i][j] * m2.values[j][k];
            }
            m.values[i][k] = el;
        }
    }
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    return m;
}


void getSquareOfMatrixIfSymmetric(matrix *m) {
    matrix m1 = mulMatrices(*m, *m);
    freeMemMatrix(m);
    *m = m1;
}


long long getSum1(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = a[i];
    }
    return sum;
}


bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) {
                return false;
            }
        }
    }
    return true;
}


void transposeIfMatrixHasNotEqualSumOfRows(matrix *m) {
    long long a[m->nRows];
    for (int i = 0; i < m->nRows; ++i) {
        a[i] = getSum1(m->values[i], m->nCols);
    }

    if (isUnique(a, m->nCols)) {
        transposeSquareMatrix(m);
    }
}


bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    transposeSquareMatrix(&m2);
    bool n = areTwoMatricesEqual(&m1, &m2);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    return n;
}


int max(int a, int b) {
    return a > b ? a : b;
}




//Lab_16