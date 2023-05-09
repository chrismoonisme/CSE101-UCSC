//Christopher Moon
//ckmoon
//pa4

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "List.h"

typedef struct MatrixObj* Matrix;

Matrix newMatrix(int n);

void freeMatrix(Matrix* pM);

int size(Matrix M);

int NNZ(Matrix M);

int equals(Matrix A, Matrix B);

void makeZero(Matrix M);

void changeEntry(Matrix M, int i, int j, double x);

void printMatrix(FILE* out, Matrix M);

Matrix copy(Matrix A);

Matrix transpose(Matrix A);

#endif
