#include<stdio.h>
#include<math.h>
int main()
{
    int n, counter, term = 3, sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    for(counter = 1; counter <= n; counter++)
    {
        sum += pow(term, 3);
        term += 3;
    }

    printf("%d", sum);
}
