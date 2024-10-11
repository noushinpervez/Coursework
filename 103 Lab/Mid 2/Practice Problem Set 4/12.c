#include<stdio.h>
int main()
{
    int i, n, j = 0;
    printf("Array Size: ");
    scanf("%d", &n);
    int a[n];
    printf("Input Array: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int b[n];

    for(i = 0; i < n; i++)
    {
        if(a[i] != 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    for(i = j; i < n; i++)
        b[i] = 0;

    printf("New Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", b[i]);
}
