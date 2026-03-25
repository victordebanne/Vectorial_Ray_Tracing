#include <stdio.h>
#include <stdlib.h>
#include "VRT.h"

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

int in_sight(Matrix* m, Vector* A, Vector* B){
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
        if(m->values[C.i][C.j] = 1) return 0;
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
    return 1;
}


