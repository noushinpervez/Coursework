#include<stdio.h>
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    if(num % 3 == 0)
    {
        if(num % 5 == 0)
            printf( "Divisible by 3 and 5");
        else
            printf("Divisible by 3");
    }
    else if(num % 5 == 0)
        printf("Divisible by 5");
    else
        printf("Not divisible by 3 or 5");
}
