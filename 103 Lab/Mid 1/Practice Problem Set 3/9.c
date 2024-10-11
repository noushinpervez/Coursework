#include<stdio.h>
int main()
{
    int n, counter, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    for(counter = 1; counter <= n; counter++)
    {
        if(n % counter == 0)
            count++;
    }

    printf("%d", count);
}
