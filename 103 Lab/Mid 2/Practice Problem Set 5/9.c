#include<stdio.h>
int main()
{
    int i, j, k, N, M;
    printf("Enter M(Number of Rows): ");
    scanf("%d", &M);
    printf("Enter N(Number of Columns): ");
    scanf("%d", &N);
    int a[M][N];
    printf("Enter Array: ");
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    }

    for(k = M - 1; k >= 0; k--)
    {
        i = k;
        j = 0;
        while(i < M)
        {
            printf("%d ", a[i][j]);
            i++;
            j++;
        }
        printf("\n");
    }
    for(k = 1; k < N; k++)
        {
            i = 0;
            j = k;
            while(j < N)
            {
                printf("%d ", a[i][j]);
                i++;
                j++;
            }
            printf("\n");
        }
}
