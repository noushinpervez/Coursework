#include<stdio.h>
int main()
{
    int i, j, N, M;
    float count = 0, count1 = 0, count2 = 0;
    printf("Enter N(Number of Rows): ");
    scanf("%d", &N);
    printf("Enter M(Number of Columns): ");
    scanf("%d", &M);
    int a[N][M];
    printf("Enter Array: ");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            scanf("%d", &a[i][j]);
            count++;
            if(a[i][j] == 0)
                count1++;
            else
                count2++;
        }
    }

    printf("Sparsity = %.2f\n", count1 / count);
    printf("Density = %.2f", count2 / count);
}
