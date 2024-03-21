#include "matrix_tasks_test.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"


void task_1_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    3, 4, 6,
                    7, 8, 9,
            },
            3, 3
    );

    sortRowsByMinAndMaxElement(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    3, 4, 6,
                    1, 2, 5,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 33, 17,
                    6, 7, 10,
                    2, 4, 3,
            }, 3, 3
    );


    matrix m4 = createMatrixFromArray(
            (int[]) {
                    1, 33, 17,
                    6, 7, 10,
                    2, 4, 3,
            }, 3, 3
    );

    sortRowsByMinAndMaxElement(&m3);

    assert(areTwoMatricesEqual(&m3,&m4)==1);

    freeMemMatrix(&m3);
    freeMemMatrix(&m4);
}


void task_2_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 8, 7,
                    5, 4, 6,
                    1, 2, 3,
            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    5, 4, 6,
                    9, 8, 7,
            },
            3, 3
    );

    sortRowsByMinElement(&m1);

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    1, 1, 1,
            },
            3, 3
    );

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    1, 1, 1,
            },
            3, 3
    );

    sortRowsByMinElement(&m3);

    assert(areTwoMatricesEqual(&m3,&m4)==1);

    freeMemMatrix(&m3);
    freeMemMatrix(&m4);
}


void task_3_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 8, 7,
                    5, 4, 6,
                    3, 2, 1,
            },
            3, 3
    );

    sortColsByMinElement(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    6, 4, 5,
                    1, 2, 3,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 1, 7,
                    5, 4, 6,
                    3, 2, 1,
            },
            3, 3
    );

    sortColsByMinElement(&m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    6, 4, 5,
                    1, 2, 3,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m3);
    freeMemMatrix(&m4);
}


void task_4_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 5, 3,
                    5, 4, 2,
                    3, 2, 1,
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    115, 71, 40,
                    71, 45, 25,
                    40, 25, 14,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(&m3,&m4)==1);

    freeMemMatrix(&m3);
    freeMemMatrix(&m4);


}


void task_5_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 5, 3,
                    5, 4, 2,
                    3, 2, 1,
            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    9, 5, 3,
                    5, 4, 2,
                    3, 2, 1,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    9, 5, 4,
                    5, 4, 9,
                    3, 2, 1,
            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(&m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    9, 5, 4,
                    5, 4, 9,
                    3, 2, 1,
            },
            3, 3
    );

    assert(areTwoMatricesEqual(&m3,&m4)==1);

    freeMemMatrix(&m3);
    freeMemMatrix(&m4);
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

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    9, 6, 3,
                    5, 4, 8,
                    3, 2, 1,
            },
            3, 3
    );

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    9, 5, 3,
                    6, 4, 2,
                    7, 8, 1,
            },
            3, 3
    );

    assert(isMutuallyInverseMatrices(m3, m4) == 0);

    freeMemMatrix(&m3);
    freeMemMatrix(&m4);
}


void task_7_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    9, 7, 7,
                    5, 4, 8,
                    3, 2, 1,
            },
            3, 3
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 23);

    freeMemMatrix(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            },
            3, 3
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m2) == 0);

    freeMemMatrix(&m2);
}


void task_8_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 7, 7,
                    5, 4, 8,
                    3, 2, 9,
            },
            3, 3
    );

    int a[3] = {1, 2, 3};

    assert(getMinInArea(m1, a) == 1);

    freeMemMatrix(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 9, 7,
                    5, 4, 8,
                    3, 2, 7,
            },
            3, 3
    );

    int b[3] = {0,1,0};

    assert(getMinInArea(m2, b) == 9);

    freeMemMatrix(&m2);
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

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    10, 11, 5, 1,
                    7, 12, 7, 4,
                    10, 11, 5, 1,
            }, 3, 4
    );

    sortByDistances(m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    10, 11, 5, 1,
                    10, 11, 5, 1,
                    7, 12, 7, 4,
            }, 3, 4
    );

    assert(areTwoMatricesEqual(&m3,&m4)==1);

    freeMemMatrix(&m3);
    freeMemMatrix(&m4);
}

void task_10_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    1, 3,
                    2, 1,
                    7, 4,
                    10, 1,
                    5, 6,
            }, 6, 2
    );

    assert(countEqClassesByRowsSum(m1)==3);

    freeMemMatrix(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 6,
                    2, 5,
                    3, 4,
                    4, 3,
                    5, 2,
                    7, 0,
            }, 6, 2
    );

    assert(countEqClassesByRowsSum(m2)==6);

    freeMemMatrix(&m2);
}


void task_11_Test() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1,1, 3,
                    2, 1,7, 4,
                    10, 1,5, 6,
            }, 3, 4
    );

    assert(getNSpecialElement(m1)==2);

    freeMemMatrix(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 1,1, 3,
                    2, 1,6, 4,
                    1, 1,5, 6,
            }, 3, 4
    );

    assert(getNSpecialElement(m2)==0);

    freeMemMatrix(&m2);

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
            }, 4, 4
    );

    assert(areTwoMatricesEqual(&m1,&m2)==1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);

    matrix m3 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 3,
                    2, 12, 7, 4,
                    10, 14, 5, 6,
                    15, 18, 8, 9
            }, 4, 4
    );

    swapPenultimateRow(m3);

    matrix m4 = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 3,
                    2, 12, 7, 4,
                    1, 2, 10, 15,
                    15, 18, 8, 9
            }, 4, 4
    );

    assert(areTwoMatricesEqual(&m3,&m4)==1);

    freeMemMatrix(&m3);
    freeMemMatrix(&m4);
}


void task_13_Test() {
    matrix *ms1 = createArrayOfMatrixFromArray(
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

    assert(countNonDescendingRowsMatrices(ms1, 4) == 3);

    freeMemMatrices(ms1,4);

    matrix *ms2 = createArrayOfMatrixFromArray(
            (int[]) {
                    1, 2,
                    1, 0,

                    1, 6,
                    2, 1,

                    5, 2,
                    2, 3,

                    3, 1,
                    1, 1,
            }, 4, 2, 2
    );

    assert(countNonDescendingRowsMatrices(ms2, 4) == 0);

    freeMemMatrices(ms2,4);

}
