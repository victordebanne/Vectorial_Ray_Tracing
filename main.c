#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int i;
    int j;
    int** values;
}Matrix;

typedef struct{
    int i;
    int j;
}Vector;

void init_matrix(Matrix* m, int i, int j){
    m->i = i;
    m->j = j;
    m->values = malloc(i * sizeof(int*));
    for(int k = 0; k < i; k++){
        m->values[k] = malloc(j * sizeof(int));
    }
    for(int k = 0; k < i; k++){
        for(int l = 0; l < j; l++){
        m->values[k][l] = 0;
        }
    }
}

void display_matrix(Matrix* m){
    for(int i = 0; i < m->i; i++){
        for(int j = 0; j < m->j; j++){
            printf("%d", m->values[i][j]);
            if(j != m->j) printf(", ");
        }
        printf("\n");
    }
}

void VRT(Matrix* m, Vector* A, Vector* B){
    Vector AB;
    AB.i = B->i - A->i;
    AB.j = B->j - A->j;
    int di = (AB.i > 0) - (AB.i < 0);
    int dj = (AB.j > 0) - (AB.j < 0);
    Vector C;
    C.i = A->i;
    C.j = A->j;
    Vector Acorner1;
    Vector Acorner2;
    int detA;
    int detB;
    int comp;
    while(C.i != B->i || C.j != B->j){
        m->values[C.i][C.j] = 1;
        Acorner1.i = C.i + di - A->i;
        Acorner1.j = C.j - A->j;
        Acorner2.i = Acorner1.i;
        Acorner2.j = Acorner1.j + dj;

        detA = Acorner1.i * AB.j - Acorner1.j * AB.i;
        detB = Acorner2.i * AB.j - Acorner2.j * AB.i;
        comp = detA * detB;
        if(comp > 0){
            C.j += dj;
        }
        else if(comp < 0){
            C.i += di;
        }
        else if(comp == 0){
            C.i += di;
            C.j += dj;
        }
    }
}


int main(){
    Vector A, B;
    A.i = 1;
    A.j = 1;
    B.i = 9;
    B.j = 8;

    Matrix M;
    init_matrix(&M, 10, 10);

    display_matrix(&M);
    printf("\n");
    VRT(&M, &A, &B);
    display_matrix(&M);

    return 0;
}
