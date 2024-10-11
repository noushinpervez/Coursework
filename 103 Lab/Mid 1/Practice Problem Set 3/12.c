#include<stdio.h>
int main()
{
    int n, x, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    while(n > 0)
    {
        x = n % 10;
        n = n / 10;
        sum = 10 * sum + x;
    }

    printf("%d", sum);
}
