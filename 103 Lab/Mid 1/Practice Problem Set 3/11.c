#include<stdio.h>
int main()
{
    int n, x;
    printf("Enter a number: ");
    scanf("%d", &n);

    while(n > 0)
    {
        x = n % 10;
        n = n / 10;
        printf("%d\t", x);
    }
}
