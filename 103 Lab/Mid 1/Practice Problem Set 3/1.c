#include<stdio.h>
int main()
{
    int n, counter;
    printf("Enter n: ");
    scanf("%d", &n);

    for(counter = 1; counter <= n; counter += 2)
        printf("%d\t", counter);
}
