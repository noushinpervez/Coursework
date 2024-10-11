#include<stdio.h>
int main()
{
    int n, counter, term = 1, sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    for(counter = 1; counter <= n; counter++)
    {
        sum += term * (term + 1) * (term + 2);
        term++;
    }

    printf("%d", sum);
}
