#include<stdio.h>
int main()
{
    int a, b, i;
    printf("Enter a & b: ");
    scanf("%d%d", &a, &b);

    for(i = a; i <= b; i++)
    {
        if(i % 3 == 0)
           printf("%d\t", i);
    }
}
