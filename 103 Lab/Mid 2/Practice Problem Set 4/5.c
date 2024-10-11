#include<stdio.h>
int main()
{
    int n, i, sum = 0;
    float ave;
    printf("Array Size: ");
    scanf("%d", &n);
    printf("Input Array: ");
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
        sum = sum + a[i];

    printf("Sum = %d\n", sum);
    ave = (float)sum / (float)n;
    printf("Ave = %.2f", ave);
}
