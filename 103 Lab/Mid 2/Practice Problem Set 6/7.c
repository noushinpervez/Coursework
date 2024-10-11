#include<stdio.h>
int main()
{
   int i, j, k, n;
   printf("Enter n: ");
   scanf("%d", &n);

   k = 0;
   for(i = 1; i <= n; i++)
   {
       for(j = 1; j <= n; j++)
       {
           if(j == i)
           {
               printf("%d", k);
               k++;
           }
           else
               printf("0");

       }
       printf("\n");
   }
}
