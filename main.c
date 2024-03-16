#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix_tasks/matrix_tasks.h"



int main() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 4, 5,
                    3, 5, 9,
            },
            3, 3
    );
    sortRowsByMinElement(&m);

    outputMatrix(m);

    freeMemMatrix(&m);

    return 0;
}
