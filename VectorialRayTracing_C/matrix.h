#ifndef MATRIX_H
#define MATRIX_H

typedef struct{
    int i;
    int j;
    int** values;
}Matrix;

typedef struct{
    int i;
    int j;
}Vector;

void init_matrix(Matrix* m, int i, int j);

void display_matrix(Matrix* m);

#endif