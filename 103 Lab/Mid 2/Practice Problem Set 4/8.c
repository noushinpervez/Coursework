#include<stdio.h>
int main()
{
    int i, n, dif, max = -999999, p = -1, q = -1;
    printf("Array Size: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the numbers: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n - 1 ; i++)
    {
        dif = a[i] - a[i + 1];
        if(dif < 0)
            dif = -1;
        if(dif > max)
        {
            printf("%d\n", dif);
            max = dif;
            p = i;
            q = i+1;
        }
    }

    printf("%d, %d", p, q);
}
