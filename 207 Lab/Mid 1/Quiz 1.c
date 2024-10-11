#include<stdio.h>

int main(void)
{
    int var1 = 10, var2 = 20;
    int *ptr = &var1;
    ptr = &var2;
    printf("%d", *ptr);
}
