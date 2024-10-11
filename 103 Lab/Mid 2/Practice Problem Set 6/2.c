#include<stdio.h>
int main()
{
    int i, j, n;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        int flag = 0;
        for(j = 2; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            printf("%d: Not composite\n", i);
        else
            printf("%d: Composite\n", i);
    }
}
