#include<stdio.h>

int main() {
    int N = 10, i, j;
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for(i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int *p = a;
    printf("*p = %d\n", *p);
    printf("*(p+4) = %d\n", *(p+4));
    printf("(*p)+4 = %d\n", (*p)+4);
    printf("*++p = %d\n", *++p);
    printf("++*p = %d\n", ++*p);

    //int matrix[ NROWS ], *iptr = matrix;
    //then the following are also equivalent:
    //matrix[ i ] = 42;
    //*( iptr + i) = 42;

    for ( i = 0; i < N; i++) {
        printf("%d ", *p++);
        //printf("%d ", *(p+i));
    }
    printf("\n");

    return 0;
}
