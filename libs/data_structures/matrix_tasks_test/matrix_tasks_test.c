#include "matrix_tasks_test.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"


void task_1_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    3, 4, 6,
                    7, 8, 9,
            },
            3, 3
    );

    sortRowsByMinAndMaxElement(&m);

    assert(m.values[0][0] == 7);
    assert(m.values[0][1] == 8);
    assert(m.values[0][2] == 9);
    assert(m.values[1][0] == 3);
    assert(m.values[1][1] == 4);
    assert(m.values[1][2] == 6);
    assert(m.values[2][0] == 1);
    assert(m.values[2][1] == 2);
    assert(m.values[2][2] == 5);

    freeMemMatrix(&m);
}


void task_2_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 8, 7,
                    5, 4, 6,
                    1, 2, 3,
            },
            3, 3
    );

    sortRowsByMinElement(&m);

    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 2);
    assert(m.values[0][2] == 3);
    assert(m.values[1][0] == 5);
    assert(m.values[1][1] == 4);
    assert(m.values[1][2] == 6);
    assert(m.values[2][0] == 9);
    assert(m.values[2][1] == 8);
    assert(m.values[2][2] == 7);

    freeMemMatrix(&m);
}


void task_3_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 8, 7,
                    5, 4, 6,
                    3, 2, 1,
            },
            3, 3
    );

    sortColsByMinElement(&m);

    assert(m.values[0][0] == 7);
    assert(m.values[0][1] == 8);
    assert(m.values[0][2] == 9);
    assert(m.values[1][0] == 6);
    assert(m.values[1][1] == 4);
    assert(m.values[1][2] == 5);
    assert(m.values[2][0] == 1);
    assert(m.values[2][1] == 2);
    assert(m.values[2][2] == 3);

    freeMemMatrix(&m);
}


void task_4_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 5, 3,
                    5, 4, 2,
                    3, 2, 1,
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);

    assert(m.values[0][0] == 115);
    assert(m.values[0][1] == 71);
    assert(m.values[0][2] == 40);
    assert(m.values[1][0] == 71);
    assert(m.values[1][1] == 45);
    assert(m.values[1][2] == 25);
    assert(m.values[2][0] == 40);
    assert(m.values[2][1] == 25);
    assert(m.values[2][2] == 14);

    freeMemMatrix(&m);

}


void task_5_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 5, 3,
                    5, 4, 2,
                    3, 2, 1,
            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(&m);

    assert(m.values[0][0] == 9);
    assert(m.values[0][1] == 5);
    assert(m.values[0][2] == 3);
    assert(m.values[1][0] == 5);
    assert(m.values[1][1] == 4);
    assert(m.values[1][2] == 2);
    assert(m.values[2][0] == 3);
    assert(m.values[2][1] == 2);
    assert(m.values[2][2] == 1);

    freeMemMatrix(&m);
}

void task_6_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 6, 7,
                    5, 4, 8,
                    3, 2, 1,
            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    9, 5, 3,
                    6, 4, 2,
                    7, 8, 1,
            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(m1, m2) == 1);


    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void task_7_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    9, 7, 7,
                    5, 4, 8,
                    3, 2, 1,
            },
            3, 3
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m) == 23);

    freeMemMatrix(&m);
}


void task_8_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 7, 7,
                    5, 4, 8,
                    3, 2, 9,
            },
            3, 3
    );

    int a[3] = {1, 2, 3};

    assert(getMinInArea(m, a) == 1);

    freeMemMatrix(&m);
}


void task_9_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 13,
                    7, 12, 7, 4,
                    10, 11, 5, 1,
            }, 3, 4
    );

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                 10, 11, 5, 1,
                 7, 12, 7, 4,
                   6, 8, 9, 13,
        }, 3, 4
    );

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void task_10_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    1, 3,
                    2, 1,
                    7, 4,
                    10, 1,
                    5, 6,
            }, 6, 2
    );

    assert(countEqClassesByRowsSum(m)==3);

    freeMemMatrix(&m);
}


void task_11_Test() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1,1, 3,
                    2, 1,7, 4,
                    10, 1,5, 6,
            }, 3, 4
    );

    assert(getNSpecialElement(m)==2);

    freeMemMatrix(&m);

}


void task_12_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    11, 13, 1, 3,
                    2, 12, 7, 4,
                    10, 14, 5, 6,
                    15, 18, 8, 9
            }, 4, 4
    );

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    11, 13, 1, 3,
                    2, 12, 7, 4,
                    1, 7, 5, 8,
                    15, 18, 8, 9
            }, 3, 4
    );

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void task_13_Test() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    1, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 2,
                    2, 3,

                    1, 3,
                    7, 8
            }, 4, 2, 2
    );

    assert(countNonDescendingRowsMatrices(ms, 4) == 3);

    freeMemMatrices(ms,4);
}
