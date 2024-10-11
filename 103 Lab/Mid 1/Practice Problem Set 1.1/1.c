#include<stdio.h>
int main()
{
    int n1, d1, n2, d2, n, d;
    printf("Enter the fractions: ");
    scanf("%d%d%d%d", &n1, &d1, &n2, &d2);

    d = d1*d2;
    n = n1*d2 + n2*d1;

    printf("%d / %d + %d / %d = %d / %d", n1, d1, n2, d2, n, d);
}
