#include<stdio.h>
int main()
{
    int i;
    printf("Enter an integer: ");
    scanf("%d", &i);

    if(i >= 0 && i <= 9)
        printf("Number of digits = 1");
    else if(i >= 10 && i <= 99)
        printf("Number of digits = 2");
    else if(i >= 100 && i <= 999)
        printf("Number of digits = 3");
    else if(i >= 1000 && i <= 9999)
        printf("Number of digits = 4");
    else if(i >= 10000 && i <= 99999)
        printf("Number of digits = 5");
}
