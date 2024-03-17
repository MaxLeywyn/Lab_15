#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix_tasks/matrix_tasks.h"



int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 3, 5,
                    0,0,0,
                    6, 3, 5,
            },
            3, 3
    );


    printf("%d", getNSpecialElement(m1));

    outputMatrix(m1);

    freeMemMatrix(&m1);

    return 0;
}
