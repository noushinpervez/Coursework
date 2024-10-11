#include<stdio.h>
int main()
{
    int n, i, j = 0;
    printf("Array Size: ");
    scanf("%d", &n);
    int a[n];
    printf("Input Array : ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int b[n];

    for(i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            b[j] = a[i];
            j++;
        }
    }

    printf("New Array Size: %d\n", j);
    printf("New Array: ");
    for(i = 0; i < j; i++)
        printf("%d ", b[i]);
}
