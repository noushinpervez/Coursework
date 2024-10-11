#include<stdio.h>

int main() {
    int a = 10;
    int *p = &a;

    printf("p = %p\n", p);
    printf("*p= %d\n\n", *p);

    p++;

    printf("p = %p\n", p);
    printf("*p= %d\n\n", *p);

    char b = 'c';
    char *q = &b;

    printf("q = %p\n", q);
    printf("*q= %d\n\n", *q);

    q++;

    printf("q = %p\n", q);
    printf("*q= %d\n\n", *q);

    p = p + 2;
    p = p - 2;

    q = q + 2;
    q = q - 2;

    return 0;
}
