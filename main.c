#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix_tasks/matrix_tasks.h"



int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    6, 3, 5,
                    0, 2, 4,
                    0, 0, 7,
            },
            3, 3
    );


    sortByDistances(m1);

    outputMatrix(m1);

    freeMemMatrix(&m1);

    return 0;
}
