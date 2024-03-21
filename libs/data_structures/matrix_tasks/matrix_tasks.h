#ifndef LAB_15_MATRIX_TASKS_H
#define LAB_15_MATRIX_TASKS_H

//Lab_16

#include "../../data_structures/matrix/matrix.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Task 1
void sortRowsByMinAndMaxElement(matrix *m);

//Task 2
void sortRowsByMinElement(matrix *m);

//Task 3
void sortColsByMinElement(matrix *m);

//Task 4
void getSquareOfMatrixIfSymmetric(matrix *m);

//Task 5
void transposeIfMatrixHasNotEqualSumOfRows(matrix *m);

//Task 6
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

//Task 7
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

//Task 8
int getMinInArea(matrix m, const int *area_array);

//Task 9
void sortByDistances(matrix m);

//Task 10
int countEqClassesByRowsSum(matrix m);

//Task 11
int getNSpecialElement(matrix m);

//Task 12
void swapPenultimateRow(matrix m);

//Task 13
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

//Task 14
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

//Task 15
void printMatrixWithMinAbsNorm(matrix *ms, int nMatrix);


#endif //LAB_15_MATRIX_TASKS_H
