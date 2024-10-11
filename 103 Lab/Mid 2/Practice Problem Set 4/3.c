#include<stdio.h>
int main()
{
    int n, i, count = 0;
    printf("Array Size: ");
    scanf("%d", &n);
    printf("Input Array: ");
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
    {
        if(a[i] < 0)
            count++;
    }

    printf("%d", count);
}
