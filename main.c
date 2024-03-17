#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix_tasks/matrix_tasks.h"



int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 5,10,
                    2,4,9,12,
                    6, 7, 8,11,
                    13,15,4,14,
            },
            4, 4
    );

    swapPenultimateRow(m1);

    outputMatrix(m1);

    freeMemMatrix(&m1);

    return 0;
}
