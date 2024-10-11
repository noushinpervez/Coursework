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

    int max = a[0][0];
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            if(a[i][j] > max)
                max = a[i][j];
        }
    }
    printf("Max Element: %d", max);
}
