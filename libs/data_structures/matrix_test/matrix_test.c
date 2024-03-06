#include "matrix_test.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


void test_getMemMatrix() {
    matrix mat = getMemMatrix(2, 2);

    assert(mat.values != 0);

    freeMemMatrix(&mat);
}

void test_getMemArrayOfMatrices() {
    int nMatrices = 3;
    int nRows = 2;
    int nCols = 2;

    matrix *array_matrix = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    for (int i = 0; i < nMatrices; i++) {
        assert(array_matrix[i].values != NULL);
    }

    freeMemMatrices(array_matrix, nMatrices);
}


void test_freeMemMatrix() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    freeMemMatrix(&test_matrix);

    assert(test_matrix.values == NULL);
}

void test_freeMemMatrices() {
    int nMatrices = 3;
    matrix ms[nMatrices];
    matrix *array_matrix = getMemArrayOfMatrices(nMatrices, ms->nRows, ms->nCols);

    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
        assert(ms[i].values == NULL);
    }
}


void test_swapRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );
    swapRows(&m, 0, 1);

    assert(m.values[0][0] == 3);
    assert(m.values[0][1] == 4);
    assert(m.values[1][0] == 1);
    assert(m.values[1][1] == 2);

    freeMemMatrix(&m);
}


void test_swapColumns() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    swapColumns(&m, 0, 1);

    assert(m.values[0][0] == 2);
    assert(m.values[0][1] == 1);
    assert(m.values[1][0] == 4);
    assert(m.values[1][1] == 3);

    freeMemMatrix(&m);
}


void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    1, 2,
            },
            2, 2
    );

    insertionSortRowsMatrixByRowCriteria(m, getSum);

    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 2);
    assert(m.values[1][0] == 3);
    assert(m.values[1][1] == 4);

    for (int i = 0; i < m.nRows; i++) {
        free(m.values[i]);
    }
    free(m.values);
}


void test_selectionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    4, 1,
                    3, 2,
            },
            2, 2
    );

    selectionSortColsMatrixByColCriteria(m, getSum);

    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 4);
    assert(m.values[1][0] == 2);
    assert(m.values[1][1] == 3);

    for (int i = 0; i < m.nRows; i++) {
        free(m.values[i]);
    }
    free(m.values);
}


void test_isSquareMatrix() {
    matrix m = getMemMatrix(3, 3);

    assert(isSquareMatrix(&m) == true);
}


void test_areTwoMatricesEqual() {
    matrix first_m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );

    matrix second_m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(&first_m, &second_m) == true);

    freeMemMatrix(&first_m);
    freeMemMatrix(&second_m);
}


void test_isEMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            },
            3, 3
    );

    assert(isEMatrix(&m) == true);

    freeMemMatrix(&m);
}


void test_isSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 4, 5,
                    3, 5, 9,
            },
            3, 3
    );

    assert(isSymmetricMatrix(&m) == true);

    freeMemMatrix(&m);
}


void test_transposeSquareMatrix() {
    matrix first_m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );

    matrix second_m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );

    transposeSquareMatrix(&first_m);
    transposeSquareMatrix(&first_m);

    assert(areTwoMatricesEqual(&first_m,&second_m)==true);

    freeMemMatrix(&first_m);
    freeMemMatrix(&second_m);
}


void test_getMinValuePos() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    1, 2, 3,
            },
            2, 3
    );
    position pos = {1, 0};

    assert(getMinValuePos(test_matrix).rowIndex == pos.rowIndex);
    assert(getMinValuePos(test_matrix).colIndex == pos.colIndex);

    freeMemMatrix(&test_matrix);
}


void test_getMaxValuePos() {
    matrix test_matrix = createMatrixFromArray(
            (int[]) {
                    4, 4, 4,
                    5, 3, 2,
            },
            2, 3
    );
    position pos = {1, 0};

    assert(getMaxValuePos(test_matrix).rowIndex == pos.rowIndex);
    assert(getMaxValuePos(test_matrix).colIndex == pos.colIndex);

    freeMemMatrix(&test_matrix);
}
