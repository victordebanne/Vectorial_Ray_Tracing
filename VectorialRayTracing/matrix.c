#include "matrix.h"

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