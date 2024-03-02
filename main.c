#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"


int main() {

    matrix m = getMemMatrix(2,2);

    inputMatrix(&m);

    outputMatrix(m);

    swapRows(&m,1,0);

    outputMatrix(m);

    freeMemMatrix(&m);

    outputMatrix(m);

    return 0;
}
