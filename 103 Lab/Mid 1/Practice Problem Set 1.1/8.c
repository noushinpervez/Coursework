#include<stdio.h>
int main()
{
    int a, b, c, d, e, f, g, h, i, j, k, l, sum, div, sub;
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);
    sum = ((a + c + e + g + i + k) + (b + d + f + h + j + l) * 3) - 1;
    div = sum % 10;
    sub = 9 - div;
    printf("%d", sub);
}
