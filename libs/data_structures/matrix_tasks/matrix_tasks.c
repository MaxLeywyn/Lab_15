#include "matrix_tasks.h"
#include <stdlib.h>
#include <math.h>


//Lab 16


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


long long sumMaxNumsInDiagonals(matrix m, bool is_row) {
    long long sum = 0;
    for (int i = 1; i < (is_row ? m.nRows : m.nCols); i++) {
        int maxNum = m.values[is_row ? i : 0][is_row ? 0 : i];
        for (int ind_c = (is_row ? 1 : i + 1), ind_r = (is_row ? i + 1 : 1);
             ind_c < m.nCols && ind_r < m.nRows; ind_c++, ind_r++) {
            if (m.values[ind_r][ind_c] > maxNum) {
                maxNum = m.values[ind_r][ind_c];
            }
        }

        sum += maxNum;
    }

    return sum;
}


long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;
    sum += sumMaxNumsInDiagonals(m, false);
    sum += sumMaxNumsInDiagonals(m, true);

    return sum;
}


int getMinInArea(matrix m, const int *area_array) {
    int min = INT_MAX;
    int ind_c = 0;
    int ind_r = 0;
    while (ind_c < m.nCols) {
        if (area_array[ind_c] == ind_r) {
            ind_r = 0;
            ind_c++;
        } else {
            if (m.values[ind_r][ind_c] < min) {
                min = m.values[ind_r][ind_c];
            }
            ind_r++;
        }
    }
    return min;
}


float getDistance(int *a, int n) {
    float sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += powf(a[i], 2);
    }
    sum = sqrtf(sum);
    return sum;
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float a[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        a[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; i++) {
        float t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
        swapRows(&m, j, i);
    }
}


void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}


int comp(const void *i, const void *j) {
    return *(long long *) i - *(long long *) j;
}


int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long int), comp);
    int max = 0;
    int counter = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == a[i + 1])
            counter++;
        else if (a[i] != a[i + 1] && counter > max) {
            max = counter;
            counter = 1;
        } else
            counter = 1;
    }
    return max;
}


int countEqClassesByRowsSum(matrix m) {
    long long a[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        a[i] = getSum1(m.values[i], m.nCols);
    }
    return countNUnique(a, m.nRows);
}


int getNSpecialElement(matrix m) {
    int a_max_el[m.nCols];
    int a_sum[m.nCols];
    memcpy(a_max_el,m.values[0],sizeof(int)*m.nCols);
    memcpy(a_sum,m.values[0],sizeof(int)*m.nCols);

    for (int i = 1; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (a_max_el[j]<m.values[i][j])
                a_max_el[j]=m.values[i][j];
            a_sum[j]+=m.values[i][j];
        }
    }

    int k = 0;

    for (int i = 0; i < m.nCols; i++) {
        if(a_sum[i]-a_max_el[i] < a_max_el[i])
            k++;
    }
    return k;
}


position getLeftMin(matrix m){
    return getMinValuePos(m);
}

void swapPenultimateRow(matrix m){
    position p = getLeftMin(m);
    int num = m.values[m.nRows-2][p.colIndex];
    for (int i = 0; i < m.nRows; ++i) {
        m.values[m.nRows-2][i]=m.values[i][p.colIndex];
        if(i==m.nRows-2)
            m.values[m.nRows-2][i]=num;
    }
}


bool isNonDescendingSorted(int *a, int n){
    for (int i = 0; i < n-1; ++i) {
        if(a[i]>a[i+1])
            return false;
    }
    return true;
}


bool hasAllNonDescendingRows(matrix m){
    for (int i = 0; i < m.nRows; ++i) {
        if(!(isNonDescendingSorted(m.values[i],m.nCols))){
            return false;
        }
    }
    return true;
}


int countNonDescendingRowsMatrices(matrix *ms, int nMatrix){
    int k = 0;
    for (int i = 0; i < nMatrix; ++i) {
        if(hasAllNonDescendingRows(ms[i]))
            k++;
    }
    return k;
}


int countValues(const int *a, int n, int value){
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if(a[i]==value)
            k++;
    }
    return k;
}


int countZeroRows(matrix m){
    int k = 0;
    for (int i = 0; i < m.nRows; ++i) {
        if(countValues(m.values[i],m.nCols,0)==m.nCols)
            k++;
    }
    return k;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix){
    int max_0 = 0;
    int a[nMatrix];
    for (int i = 0; i < nMatrix; ++i) {
        a[i]=countZeroRows(ms[i]);
        if(max_0<a[i])
            max_0=a[i];
    }

    for (int i = 0; i < nMatrix; ++i) {
        if(a[i]==max_0)
            outputMatrix(ms[i]);
    }
}


int getMaxAbsValue(matrix m) {
    int max = abs(m.values[0][0]);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (abs(m.values[i][j]) > max) {
                max = abs(m.values[i][j]);
            }
        }
    }

    return max;
}


int getMin(const int *a, int n){
    int min = a[0];
    for (int ind = 1; ind < n; ind++){
        if (a[ind] < min){
            min = a[ind];
        }
    }

    return min;
}


void printMatrixWithMinAbsNorm(matrix *ms, int nMatrix) {
    int arrayMaxAbsNorms[nMatrix];

    for (int i = 0; i < nMatrix; i++) {
        arrayMaxAbsNorms[i] = getMaxAbsValue(ms[i]);
    }

    int min_norm = getMin(arrayMaxAbsNorms, nMatrix);
    for (int i = 0; i < nMatrix; i++) {
        if (arrayMaxAbsNorms[i] == min_norm) {
            outputMatrix(ms[i]);
        }
    }
}




//Lab_16