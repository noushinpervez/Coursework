#include<stdio.h>
int main()
{
   int i, j, n, sum = 0, mul;
   printf("Enter n: ");
   scanf("%d", &n);

   for(i = 1; i <= n; i++)
   {
       mul = 1;
       for(j = 1; j <= i; j++)
           mul *= j;

        sum += mul;
   }
   printf("%d", sum);
}
