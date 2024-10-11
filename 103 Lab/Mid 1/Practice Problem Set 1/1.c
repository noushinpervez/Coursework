#include<stdio.h>
// this program will calculate the product of three integers
int main()
{
    int x, y, z, result;
    printf("Enter x, y, z: ");
    scanf("%d%d%d", &x, &y, &z );
    result = x * y * z;
    printf("%d", result);
}
