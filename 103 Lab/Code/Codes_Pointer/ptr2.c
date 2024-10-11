#include<stdio.h>

int main() {
    int *x, *y, z = 40;
    x = &z; // x now points to the address of z
    printf("x = %d\n", x);
    printf("z = %d\n", z);
    printf("y = %p\n\n", y);

    *x = 30;
    printf("x = %p\n", x);
    printf("z = %d\n", z);
    printf("y = %p\n\n", y);

    //*y = 15; // The program crashes because y does not point to anything
    printf("x = %p\n", x);
    printf("z = %d\n", z);
    printf("y = %p\n\n", y);

    y = x;
    printf("x = %p\n", x);
    printf("z = %d\n", z);
    printf("y = %p\n\n", y);

    *y = 15;
    printf("x = %p\n", x);
    printf("z = %d\n", z);
    printf("y = %p\n\n", y);


    double a  =100;
    *x = &a;
    printf("x = %p\n", x);
    printf("a = %lf\n\n", a);

    *x = 199;
    printf("x = %p\n", x);
    printf("a = %lf\n\n", a);
    return 0;
}
