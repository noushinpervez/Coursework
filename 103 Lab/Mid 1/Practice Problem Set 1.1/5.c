#include<stdio.h>
int main()
{
    int a, b, c, d;
    scanf("%d%d%d", &a, &b, &c);
    printf("Before Swap: a = %d, b = %d, c = %d\n", a, b, c);

    d = c;
    c = b;
    b = a;
    a = d;

    printf("After right cyclic shift: a = %d, b = %d, c = %d", a, b, c);
}
