#include<stdio.h>
int main()
{
    int i, j, N, M, n, m;
    printf("Enter N(Number of Rows): ");
    scanf("%d", &N);
    printf("Enter M(Number of Columns): ");
    scanf("%d", &M);
    int a[N][M];
    printf("Enter Array: ");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Enter n(Number of Rows): ");
    scanf("%d", &n);
    printf("Enter m(Number of Columns): ");
    scanf("%d", &m);
    int b[n][m];
    printf("Enter Array: ");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
    }

    printf("%d %d\n", N, m + M);
    if(N == n)
    {
        int c[N][m + M];
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
                c[i][j] = a[i][j];
            for(j = 0; j < m; j++)
                c[i][j + M] = b[i][j];
        }

        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M + m; j++)
                printf("%d ", c[i][j]);

            printf("\n");
        }
    }
    else
        printf("Not possible to horizontally stack the two arrays");
}
