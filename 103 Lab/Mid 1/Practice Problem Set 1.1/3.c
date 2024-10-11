#include<stdio.h>
int main()
{
    int x, d1, d2, d3, d4, d5;
    printf("Enter a number between 0 to 32767: ");
    scanf("%d", &x);

    d5 = x%8;
    x /= 8;
    d4 = x%8;
    x /= 8;
    d3 = x%8;
    x /= 8;
    d2 = x%8;
    x /= 8;
    d1 = x%8;

    printf("%d%d%d%d%d", d1, d2, d3, d4, d5);
}
