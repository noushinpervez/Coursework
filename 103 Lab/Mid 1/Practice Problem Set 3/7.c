#include<stdio.h>
#include<math.h>
int main()
{
    int n, counter, term = 1, sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    for(counter = 1; counter <= n; counter++)
    {
        sum += term * (pow(3, term));
        term++;
    }

    printf("%d", sum);
}
