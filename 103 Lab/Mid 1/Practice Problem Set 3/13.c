#include<stdio.h>
#include<math.h>
int main()
{
    int n, x, n1, i = 0, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    n1 = n;
    while(n1 != 0)
    {
        n1 /= 10;
        i++;
    }

    n1 = n;
    while(n1 != 0)
    {
        x = n1 % 10;
        sum += pow(x, i);
        n1 /= 10;
    }

    if(sum == n)
        printf("Armstrong Number");
    else
        printf("Not an Armstrong Number");
}
