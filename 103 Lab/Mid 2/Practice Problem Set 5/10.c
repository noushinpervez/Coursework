#include<stdio.h>
int main()
{
    int i, j, k = 0, r, c, p, q, flag = 0;
    printf("Enter r: ");
    scanf("%d", &r);
    printf("Enter c: ");
    scanf("%d", &c);
    int a[r][c];
    printf("Enter Array: ");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Enter p & q: ");
    scanf("%d%d", &p, &q);

    if(r * c == p * q)
    {
        printf("%d %d\n", p, q);
        int b[r * c];
        k = 0;
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                b[k] = a[i][j];
                k++;
            }
        }
        int d[p][q];
        k = 0;
        for(i = 0; i < p; i++)
        {
            for(j = 0; j < q; j++)
            {
                d[i][j] = b[k];
                k++;
            }
        }
        for(i = 0; i < p; i++)
        {
            for(j = 0; j < q; j++)
                printf("%d ", d[i][j]);

            printf("\n");
        }
    }
    else
        printf("Not possible");
}
