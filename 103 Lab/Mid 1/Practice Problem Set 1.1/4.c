#include<stdio.h>
int main()
{
    int x, b1, b2, b3, b4, b5;
    printf("Enter a number between 0 to 31: ");
    scanf("%d", &x);

    b5 = x%2;
    x /= 2;
    b4 = x%2;
    x /= 2;
    b3 = x%2;
    x /= 2;
    b2 = x%2;
    x /= 2;
    b1 = x%2;

    printf("%d%d%d%d%d", b1, b2, b3, b4, b5);
}
