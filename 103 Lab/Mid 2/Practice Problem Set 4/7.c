#include<stdio.h>
int main()
{
    int i, n, min = 999999999, min2 = 999999999;
    printf("Array Size: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the numbers: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
    {
        if(a[i] < min)
        {
            min2 = min;
            min = a[i];
        }
        else if(a[i] < min2 && a[i] > min)
            min2 = a[i];
    }

    printf("Min = %d, 2nd Min = %d\n", min, min2);
}
