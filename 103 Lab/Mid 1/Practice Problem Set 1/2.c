#include<stdio.h>
int main()
{
    int x, y;
    printf("Enter x, y : ");
    scanf("%d%d", &x, &y);

    printf("Sum = %d\n", x + y);
    printf("Subtraction = %d\n", x - y);
    printf("Multiplication = %d\n", x * y);
    printf("Division = %d\n", x / y);
    printf("Remainder = %d", x % y);
}
