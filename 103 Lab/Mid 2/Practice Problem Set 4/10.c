#include<stdio.h>
int main()
{
    int i, n, m, flag = 0, count = 0;
    printf("Input Array1 Size: ");
    scanf("%d", &n);
    int a[n];
    printf("Input Array1: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Input Array2 Size: ");
    scanf("%d", &m);
    int b[m];
    printf("Input Array2: ");
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);

    if(n == m)
    {
        for(i = 0; i < n; i++)
        {
            if(a[i] != b[i])
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag == 1 || n != m)
        printf("Not Equal");
    else
        printf("Equal");
}
