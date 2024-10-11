#include<stdio.h>
int main()
{
    int a, b, c, d;
    scanf("%d%d%d", &a, &b, &c);
    printf("Before Swap: a = %d, b = %d, c = %d\n", a, b, c);

    d = a;
    a = b;
    b = c;
    c = d;

    printf("After left cyclic shift: a = %d, b = %d, c = %d", a, b, c);
}
