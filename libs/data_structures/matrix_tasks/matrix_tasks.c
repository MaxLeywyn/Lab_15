#include "matrix_tasks.h"
#include <stdlib.h>
#include <assert.h>


void task1(){
    matrix test_m = createMatrixFromArray(
            (int[]) {
                    1, 3, 5,
                    4, 10, 2,
                    7,8,9,
            },
            3, 3
    );

    int n1 = getMaxValuePos(test_m).rowIndex;
    int n2 = getMinValuePos(test_m).rowIndex;

    swapRows(&test_m,n1,n2);

    assert(test_m.values[0][0] == 4);
    assert(test_m.values[0][1] == 10);
    assert(test_m.values[0][2] == 2);
    assert(test_m.values[1][0] == 1);
    assert(test_m.values[1][1] == 3);
    assert(test_m.values[1][2] == 5);

    freeMemMatrix(&test_m);
    freeMemMatrix(&test_m);
}






//Lab_16