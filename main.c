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

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 5, 1,
                    2, 1, 2,
                    4, 3, 4,
            },
            3, 3
    );

    matrix m = mulMatrices(m1,m2);

    freeMemMatrix(&m);

    return 0;
}
