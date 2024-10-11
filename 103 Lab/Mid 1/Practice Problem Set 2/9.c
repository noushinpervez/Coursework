#include<stdio.h>
int main()
{
    int w;
    printf("Enter a wind speed (in knots): ");
    scanf("%d", &w);

    if(w < 1)
        printf("Calm");
    else if(w <= 3)
        printf("Light Air");
    else if(w <= 27)
        printf("Breeze");
    else if(w <= 47)
        printf("Gale");
    else if(w <= 63)
        printf("Storm");
    else if(w > 63)
        printf("Hurricane");
}
