#include<stdio.h>
int main()
{
    int h1, m1, h2;
    printf("Enter 24 hour time format: ");
    scanf("%d%d", &h1, &m1);

    if(h1 > 12 && h1 < 24)
        h2 = h1 - 12;
    else if(h1 == 24)
        h2 = 0;
    else if(h1 == 12)
        h2 = 12;
    else
        h2 = h1;

    printf("%d : %.2d", h2, m1);
}
