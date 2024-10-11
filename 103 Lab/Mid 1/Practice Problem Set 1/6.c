#include<stdio.h>
int main()
{
    int i, s1, s2, s3, d1, d2;
    printf("Enter an integer: ");
    scanf("%d", &i);
    s1 = i % 10;
    d1 = i / 10;
    s2 = d1 % 10;
    d2 = d1 / 10;
    s3 = d2 % 10;
    printf("%d\t%d\t%d\t", s3, s2, s1);
}
