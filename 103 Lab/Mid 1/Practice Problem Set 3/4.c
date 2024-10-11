#include<stdio.h>
int main()
{
    int a, b, i, mul = 1;
    printf("Enter a & b: ");
    scanf("%d%d", &a, &b);

    for(i = 1; i <= b; i++)
        mul *= a;

    printf("%d", mul);
}
