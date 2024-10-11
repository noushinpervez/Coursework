#include<stdio.h>
int main()
{
    int i, j, N, M;
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

    printf("After Flipping:\n");
    for(i = 0; i < N; i++)
    {
        for(j = M - 1; j >= 0; j--)
            printf("%d ", a[i][j]);

        printf("\n");
    }
    printf("After Inverting:\n");
    for(i = 0; i < N; i++)
    {
        for(j = M - 1; j >= 0; j--)
        {
            if(a[i][j] == 0 && a[i][j] != 1)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}
