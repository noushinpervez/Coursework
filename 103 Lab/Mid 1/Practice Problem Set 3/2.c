#include<stdio.h>
int main()
{
    int n, counter;
    printf("Enter n: ");
    scanf("%d", &n);

    for(counter = 1; counter <= n; counter++)
        printf("%d\t", 2 * counter - 1);
}
