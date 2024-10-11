#include<stdio.h>
int main()
{
    int n, i, sum1 = 0, sum2 = 0;
    printf("Array Size: ");
    scanf("%d", &n);
    printf("Input Array: ");
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Output Array: ");
    for(i = 0; i < n; i++)
    {
        if(a[i] % 2 != 0)
        {
            sum1 = a[i] + 3;
            printf("%d ", sum1);
        }
        else if(a[i] % 2 == 0)
        {
            sum2 = a[i] + 2;
            printf("%d ", sum2);
        }
    }
}
