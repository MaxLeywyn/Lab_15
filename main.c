#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix_tasks/matrix_tasks.h"



int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 1,
                    4, 2, 2,
                    0, 1, 7,
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m1);

    outputMatrix(m1);

    freeMemMatrix(&m1);

    return 0;
}
