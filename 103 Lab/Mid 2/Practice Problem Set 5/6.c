#include<stdio.h>
int main()
{
    int i, j, N, M, flag = 0;
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

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            if((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0))
                flag = 1;
        }
    }

    if(flag == 0)
        printf("Yes");
    else
        printf("No");
}
