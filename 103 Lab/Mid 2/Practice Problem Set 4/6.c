#include<stdio.h>
int main()
{
    int i, n, x, loc = -1;
    printf("Array Size: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the numbers: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the number to search: ");
    scanf("%d", &x);

    for(i = n - 1; i >= 0; i--)
    {
        if (a[i] == x)
        {
            loc = i;
            break;
        }
    }

    if(loc != -1)
        printf("%d", loc);
    else
        printf("Not Found");
}
