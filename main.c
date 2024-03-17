#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix_tasks/matrix_tasks.h"



int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 2, 0,
                    0, 0, 7,
            },
            3, 3
    );

    printf("%lld",findSumOfMaxesOfPseudoDiagonal(m1));

    freeMemMatrix(&m1);

    return 0;
}
