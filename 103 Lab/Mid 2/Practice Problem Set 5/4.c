#include<stdio.h>
int main()
{
    int i, j, M, N, m, n;
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
    printf("Enter new number of Rows: ");
    scanf("%d", &m);
    printf("Enter new number of Columns: ");
    scanf("%d", &n);
    int b[m][n];

    printf("%d %d\n", m, n);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
