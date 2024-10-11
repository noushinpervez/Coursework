#include<stdio.h>
int main()
{
    float x, val;
    printf("Enter the value: ");
    scanf("%f", &val);

    if(val < 2500)
        x = 30 + 0.017 * val;
    else if(val <= 6250)
        x = 56 + .0066 * val;
    else if(val <= 20000)
        x = 76 + .0034 * val;
    else if(val <= 50000)
        x = 100 + .0022 * val;
    else if(val <= 500000)
        x = 155 + .0011 * val;
    else if(val > 500000)
        x = 255 + .0009 * val;

    if(x < 39)
        printf("$39.00");
    else
        printf("$%.2f", x);
}
