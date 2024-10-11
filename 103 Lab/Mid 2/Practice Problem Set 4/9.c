#include<stdio.h>
int main()
{
    int i, j, n, flag = 0;
    printf("Array Size: ");
    scanf("%d", &n);
    printf("Enter the numbers: ");
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n / 2; i++)
    {
        if(a[i] != a[n - 1 - i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("Yes");
    else
        printf("No");
}
