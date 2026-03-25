#include "matrix.h"
#include "VRT.h"


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