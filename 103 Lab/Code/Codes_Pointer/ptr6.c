#include<stdio.h>

int main() {
    int N1 = 4, N2 = 4, i, j;
    int b[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    for(i = 0; i < N1; i++) {
        for( j = 0; j < N2; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //int matrix[ NROWS ][ NCOLS ], * iptr = matrix;
    //then the following are also equivalent:
    //matrix[ i ][ j ] = 42;
    //*( iptr + i * NCOLS + j ) = 42;

    int *p = b;
    for(i = 0; i < N1; i++) {
        for( j = 0; j < N2; j++){
            printf("%d ", *(p + i*N2 + j));
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
